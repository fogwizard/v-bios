#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "zip.h"
#include <sys/stat.h>  

static unsigned char *pbuf=NULL;

int file_size2(const char* filename)  
{  
	struct stat statbuf;  
	stat(filename,&statbuf);  
	return (int)(statbuf.st_size);  
}  
int test_header(unsigned char *data)
{
	unsigned char *p=data;
	struct struct_zip *zip=NULL;
	if(NULL==p)return -EACCES;
	if(*p++!=0x1F){
		printf("File Type Error,line=%d,Exit Now\n",__LINE__);
		return -EAGAIN;
	}
	if(*p++!=0x8B){
		printf("File Type Error,line=%d,Exit Now\n",__LINE__);
		return -EAGAIN;
	}
	if(*p++!=0x08){
		printf("File Type Error,line=%d,Exit Now\n",__LINE__);
		return -EAGAIN;
	}
	return 0;
}
int do_gunzip(const char *name)
{
	int i,j;
	FILE * f;
	unsigned char *p=NULL;
	printf("Input File is:%s\n",name);
	if(NULL==name){
		printf("Missing Input File,Exit Now\n");
		return 0;
	}
	i=file_size2(name);
	printf("file size=%d\n",i);
	pbuf=(unsigned char *)malloc(i);
	if(NULL==pbuf){
		printf("Malloc Error,Exit Now\n");
		exit;
	}
	f=fopen(name,"r");
	fread(pbuf,i,1,f);
	p=pbuf;
	fclose(f);
	if(test_header(p)){
		printf("File Type Error,Exit Now\n");
		free(pbuf);
		exit;
	}
	free(pbuf);
	return 0;
}
