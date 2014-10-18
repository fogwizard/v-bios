#include "Typedef.h"
#include "stdlib.h"

static const byte c_chHex2dec[]=\
{
    '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','0'
};
int (atoi)(const char *fmt)
{
    byte i;
    byte c;
    int sum;
    if(NULL==fmt)
    {
        return NULL;
    }
    if(('0'==fmt[0])&&(('x'==fmt[1])||('X'==fmt[1])))
    {
        sum=0;
        for (i = 2; ((fmt[i])&&(i < 10)); ++i)//32 bit support
        {
            c=fmt[i];
            switch(c)
            {
                case 'a':
                case 'A':
                    c=10;
                    break;
                case 'b':
                case 'B':
                    c=11;
                    break;
                case 'c':
                case 'C':
                    c=12;
                    break;
                case 'd':
                case 'D':
                    c=13;
                    break;
                case 'e':
                case 'E':
                    c=14;
                    break;
                case 'f':
                case 'F':
                    c=15;
                    break;
                default:
                    c-='0';
                    break;
            }
            sum*=16;
            sum+=c;
        }
        return sum;
    }
    sum=0;
    for(i=0;((fmt[i])&&(i<16));i++)//support max 16 char
    {
        sum*=10;
        sum+=(fmt[i]-'0');
    }
    return sum;
}
