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
		if('0'==c){
			do_gzip(argv[1]);
		}else{
			do_gunzip(argv[1]);
		}
	}while((c!='0')&&(c!='1'));
	return 0;
}
