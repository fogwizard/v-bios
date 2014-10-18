#include "Typedef.h"
#include "util.h"
#include "SysCall.h"
#include "stdio.h"
#include "stdlib.h"
#include "flash.h"

bool usase(void)
{
	printf("Bad argument,Use flashrw -r/w addr len/dat\r\n");
}
static int main(int argc,char *argv[])
{
    int Addr;
    int ReadLen;
    int i;
    byte c;
    for (i = 0; i < argc; ++i)
    {
        //printf("argv[%d]=%s\r\n",i,argv[i]);
    }
    if(4!=argc)
    {
    	usase();
    	return false;
    }
    if(0==strcmp("-w",argv[1]))
    {
        Addr=atoi(argv[2]);
        c      =atoi(argv[3]);
        write_one_byte_to_flash(Addr,c);
        printf("Write %d addr to 0x[%x]\r\n",Addr,c);
    }
    else if(0==strcmp("-r",argv[1]))
    {
        Addr   =atoi(argv[2]);
        ReadLen=atoi(argv[3]);
        for(i=0;i<ReadLen;i++)
        {
            c=read_one_byte_from_flash(Addr++);
            printf("%x,",c);
        }
    }
    return true;
}

INSTALLAPP(flashrw,main);