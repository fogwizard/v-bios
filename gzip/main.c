#include <stdio.h>
#include "zip.h"
int main(int argc,char **argv)
{
	char c;
	do{
		printf("Please Select gzip or gunzip\n");
		printf("0---gzip \n");
		printf("1---gunzip \n");
		c=getchar();
	}while((c!='0')&&(c!='1'));
	return 0;
}
