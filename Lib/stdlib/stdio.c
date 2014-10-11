#include "Typedef.h"
#include "util.h"
#include "Uart.h"
#include "string.h"

#undef LEFT
#undef SIGN
#undef SPACE
#undef PLUS
#undef ZERO
#undef SIGNINT

#define PrintBufMax 512

#define LEFT 0x01
#define SIGN 0x02
#define SPACE 0x04
#define PLUS 0x08
#define ZERO 0x10
#define SIGNINT 0x20


static char *NumToAscii(char *pBuf,UINT32 nNum,int nWidth,int nBase,int nOutputStyle)
{
	char chTempArray[32], chFillChar, chSign = '\0';
	const char *pchDigit = "0123456789abcdef";
	int nCount = 0;
	int nPrefixNum = 0;


	chFillChar = (nOutputStyle & ZERO) ? '0' : ' ';//set ZERO attribute

	//set SIGN and SPACE
	if (nOutputStyle & SIGN && (10 == nBase))
	{
		if (nNum & 0x1 << 31)
		{
			chSign = '-';
			nNum = -nNum;
		}
		else if (!(nOutputStyle & SIGNINT))
		{
			chSign = '+';
		}
	}
	else if (!((nOutputStyle & SIGN) || (nNum & 0x1 << 31)) && (10 == nBase) && (nOutputStyle & SPACE))
		chSign = ' ';

	//if num == 0
	if (nNum == 0)
		chTempArray[nCount++] = '0';

	//convert number
	while (nNum != 0)
	{
		chTempArray[nCount++] = pchDigit[nNum % nBase];
		nNum = nNum / nBase;
	}

	//set PLUS
	if (nOutputStyle & PLUS)
	{
		if (nBase == 16)//handle hex
			nPrefixNum = 2;
		if (nBase == 8)//handle oct
			nPrefixNum = 1;
	}

	//EccGenerate number of chFillChar
	nWidth = nWidth - nPrefixNum - (chSign ? 1 : 0) - nCount;

	if (!(nOutputStyle & LEFT))
	{
		while (nWidth-- > 0)
			*pBuf++ = chFillChar;
	}

	switch(nPrefixNum)
	{
	case 2:
		*pBuf++ = '0';
		*pBuf++ = 'x';
		break;
	case 1:
		*pBuf++ = '0';
		break;
	default :
		break;
	}

	if (chSign)
		*pBuf++ = chSign;

	while (nCount > 0)
		*pBuf++ = chTempArray[--nCount];

	while (nWidth-- > 0)
		*pBuf++ = chFillChar;

	return pBuf;
}
static int (vsprintf)(char *pchBuf, const char *pchFormat, int *pPara)
{
	int nOutputStyle, nWidth, nBase;
	const char *pchFmtRoll;
	char *pchStrTemp;
	int nStrLen;
	char chTempArray[32];
	int nCount = 0;
	char *pchBufTemp = pchBuf;


	while (*pchFormat)
	{
		if ('%' != *pchFormat)
		{
			*pchBufTemp++ = *pchFormat++;
			continue;
		}
		pchFmtRoll = pchFormat++;

		if ('%' == *pchFormat)//handle e.g "%%"
		{
			*pchBufTemp++ = *pchFormat++;
			continue;
		}
		pchFormat--;

		nOutputStyle = 0;
get_sign :
		pchFormat++;//skip '%', handle next charactor, and record current position
		switch(*pchFormat)
		{
		case '-' :
			nOutputStyle |= LEFT;
			nOutputStyle &= (~ZERO);
			goto get_sign;
		case '+' :
			nOutputStyle |= SIGN;
			goto get_sign;
		case ' ' :
			nOutputStyle |= SPACE;
			goto get_sign;
		case '#' :
			nOutputStyle |= PLUS;
			goto get_sign;
		case '0' :
			if (!(nOutputStyle & LEFT))
				nOutputStyle |= ZERO;
			goto get_sign;
		}

		nWidth = 0;

		while (ISDIGIT(*pchFormat))
		{
			nWidth = nWidth * 10 + *pchFormat - '0';
			pchFormat++;
		}

		//handle '*',replace '*'
		if ('*' == *pchFormat)
		{
			pchFormat++;

			if (!ISDIGIT(*pchFormat))
			{
				nOutputStyle &= ~LEFT;
				nWidth = *pPara++;
			}
			else
			{
				while (*pPara)
				{
					chTempArray[nCount++] = *pPara%10 + '0';
					*pPara /= 10;
				}

				while (nCount)
					(*pchBufTemp++) = chTempArray[--nCount];

				pPara++;
				continue;
			}
		}

		nBase = 10;

		//fixme:handle '%l(o,x,i,d)' and '%ll(o,x,i,d)',filter 'l' and 'll'
		if (('l' == *pchFormat) && ('l' == *++pchFormat))
			*pchFormat ++;

		switch(*pchFormat)
		{
		case 'u':
			nBase = 10;
			nOutputStyle &= ~(SIGN | PLUS);
			break;

		case 'd' :
		case 'i' :
			nBase = 10;
			if (!(nOutputStyle & SIGN))
				nOutputStyle |= SIGNINT | SIGN;
//			nOutputStyle &= (~PLUS);
			break;
		case 'p' :
			nOutputStyle |= PLUS;
		case 'X' :
		case 'x' :
			nBase = 16;
//			nOutputStyle &= (~(SPACE | SIGN));
			break;
		case 'o' :
			nBase = 8;
//			nOutputStyle &= (~(SPACE | SIGN));
			break;
		case 's' :
//			nBase = -1;//nBase = -1 indicates output string
			pchStrTemp = (char *)*pPara;
			nStrLen = strlen(pchStrTemp);
			if (!(nOutputStyle & LEFT))
			{
				if (nOutputStyle & ZERO)
				{
					while (nWidth-- > nStrLen)
						*pchBufTemp++ = '0';
				}
				else
				{
					while (nWidth-- > nStrLen)
						*pchBufTemp++ = ' ';
				}
			}
			while (*pchStrTemp)
				*pchBufTemp++ = *pchStrTemp++;
			while (nWidth-- > nStrLen)
				*pchBufTemp++ = ' ';
			pPara++;
			pchFormat++;
			continue;
		case 'c' :
//			nBase = -2;//nBase = -2 indicates output charactor
			if (!(nOutputStyle & LEFT))
			{
				if (nOutputStyle & ZERO)
				{
					while (nWidth-- > 1)
						*pchBufTemp++ = '0';
				}
				else
				{
					while (nWidth-- > 1)
						*pchBufTemp++ = ' ';
				}
			}
			*pchBufTemp++ = (char)*pPara;
			while (nWidth-- > 1)
				*pchBufTemp++ = ' ';
			pPara++;
			pchFormat++;
			continue;
		default  :
			*pchBufTemp++ = *pchFmtRoll++;
			pchFormat = pchFmtRoll;//roll back pchFormat
			continue;
		}
	pchBufTemp = NumToAscii(pchBufTemp, *pPara, nWidth, nBase, nOutputStyle);
	pPara++;
	pchFormat++;
	}
	*pchBufTemp = '\0';

	return pchBufTemp - pchBuf;
}


int (printf)(const char *fmt, ...)
{
    char buf[512];
    int i,HowManyChar;
    int *ParamNext=(int *)(&fmt)+1;
    HowManyChar=vsprintf(buf,fmt,ParamNext);
    for (i = 0;(i < PrintBufMax)&&(buf[i]); ++i)//print
    {
	Uart0PrintChar(buf[i]);
    }
    return HowManyChar;
}
