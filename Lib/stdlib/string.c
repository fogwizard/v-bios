#include "Typedef.h"
#include "string.h"

int (strlen)(const char *fmt)
{
    int i;
    if(NULL==fmt)return -1;
    for (i = 0; i < 0xffff;)
    {
	 if(fmt[i])
	 {
	     i++;
	     continue;
	 }
	 break;
    }
    return i;
}

int (strcmp) (char *str1, char *str2)
{
    if((NULL==str1)||(NULL==str2))//err have occur
    {
	return -1;
    }
    while ((*str1) && (*str2) && (*str1 == *str2))
    {
      str1++;
      str2++;
    }
  return (*str1 - *str2);
}
void *(memset)(void *s,int ch,int n)
{
	unsigned char *dest=(unsigned char *)s;
	unsigned char c=(unsigned char)ch;
	if(NULL==s)return NULL;
	for(;n>0;--n)
	{
		*dest++=c;
	}
}
