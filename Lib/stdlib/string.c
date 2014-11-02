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
char * (strcpy)(char *dest,const char *source)
{
    char *to=dest;
    if((NULL==dest)||(NULL==source))
    {
        return NULL;
    }
    while(*source)
    {
        *to++=*source++;
    }
    *to='\0';
    return dest;
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
int (memcmp)(const void *s1,const void *s2,size_t n)
{
    const unsigned char *source=(unsigned char *)(s1);
    const unsigned char *dest=(unsigned char *)(s2);
    if((NULL==s1)||(NULL==s2))
    {
        return -1;/*Err*/
    }
    for (;n>0;--n)
    {
        if((*source)!=(*dest))
        {
            return (*source-*dest);
        }
        ++source;
        ++dest;
    }
    return 0;
}
void * (memcpy)(void *s1,const void *s2,size_t n)
{
    const unsigned char *source=(unsigned char *)(s2);
          unsigned char *dest=(unsigned char *)(s1);
    if((NULL==s1)||(NULL==s2))
    {
        return NULL;/*Err*/
    }
    for (;n>0;--n)
    {
        *dest++=*source++;
    }
    return s1;
}
