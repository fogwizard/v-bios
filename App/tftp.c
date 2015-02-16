#include "Typedef.h"
#include "util.h"
#include "SysCall.h"
#include "stdio.h"
#include "atag.h"
#include "s3c24xxreg.h"
#include "string.h"
#include "kermit.h"
#include "arm.h"
#include "errno.h"
#include "net.h"

#define FILENAME_MAX 32

static usage(void)
{
    printf("use command like: tftp 192.168.2.1 get zImage.bin\r\n");
}
static bool ip_to_long(UINT32 *nip,char *args)
{
    return true;
}
static bool   long_to_ip(UINT32 nip,char *args)
{
    return true;
}

static bool ack_pack(tag_sock *pSock,int fd)
{   
    sendto(fd);
    recvfrom(fd);
    return true;
}

static bool tftp_aqst_file(tag_sock *pSock,int fd)
{
    return true;
}
static bool tftp_recv_file(tag_sock *pSock,void *addr,int fd)
{
    byte *pLoad=(byte *)addr;
    while(true)
    {
        ack_pack(pSock,fd);
        break;//debug
    }  
}

static int main(int argc,char * argv[])
{
    //UINT32 wNip;
    UINT32 wSip;
    UINT32 wDownLoadAddr;
    int fd;
    char chFileNameBuf[FILENAME_MAX];
    char *pchFileName=chFileNameBuf;
    tag_sock *pSock=NULL;

    if((4!=argc)&&(5!=argc))
    {
        usage();
        return E2BIG;
    }
    if(false==ip_to_long(&wSip,argv[1]))
    {
        printf("sever ip error\r\n");
        usage();
        return EAGAIN;
    }
    if((0!=strcmp("get",argv[2]))&&(0!=strcmp("GET",argv[2]))&&(0!=strcmp("Get",argv[2])))
    {
        printf("put file not support now,use get please\r\n");
        usage();
        return EAGAIN;
    }
    strcpy(pchFileName,argv[3]);//get the name
    if(5==argc)//user addr
    {
        wDownLoadAddr=atoi(argv[4]);
    }
    else//default addr
    {
        wDownLoadAddr=0x30008000;
    }
    fd=sock_alloc();
    tftp_aqst_file(pSock,fd);
    tftp_recv_file(pSock,(void *)wDownLoadAddr,fd);
    sock_close(fd);
    return 0;
}

INSTALLAPP(tftp, main);