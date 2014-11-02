#include "Typedef.h"
#include "util.h"
#include "SysCall.h"
#include "stdio.h"
#include "atag.h"
#include "s3c24xxreg.h"
#include "string.h"
#include "kermit.h"
#include "arm.h"


atag *set_tag_core(atag *tAddr)
{
    atag *ptAtag=(atag *)tAddr;
    ptAtag->tHeader.wSize=2+sizeof(tag_core)/(sizeof(UINT32));
    ptAtag->tHeader.wFlag=ATAG_CORE;
    ptAtag->tTagType.tCore.wFlag=0;
    ptAtag->tTagType.tCore.wPageSize=0;
    ptAtag->tTagType.tCore.wRootDev=0;
    return (atag *)((long*)tAddr+ ptAtag->tHeader.wSize);
}
atag *set_tag_mem(atag * tAddr)
{
    atag *ptAtag=(atag *)tAddr;
    ptAtag->tHeader.wSize=2+sizeof(tag_mem)/(sizeof(UINT32));
    ptAtag->tHeader.wFlag=ATAG_MEM;
    ptAtag->tTagType.tMem.wSize=SDRAM_SIZE;
    ptAtag->tTagType.tMem.wStart=SDRAM_BASE;
    return (atag *)((long *)tAddr+ptAtag->tHeader.wSize);
}
atag *set_tag_serial(atag * tAddr)
{
    atag *ptAtag=(atag *)tAddr;
    ptAtag->tHeader.wSize=2+sizeof(tag_serial)/(sizeof(UINT32));
    ptAtag->tHeader.wFlag=ATAG_SERIAL;
    return (atag *)(((long *)tAddr+ptAtag->tHeader.wSize));
}
atag *set_tag_cmdline(atag * tAddr,char *buf)
{
    atag *ptAtag=(atag *)tAddr;
    while(' '==*buf)
    {
        buf++;
    }
    ptAtag->tHeader.wSize=2+((strlen(buf)+3)>>2);
    ptAtag->tHeader.wFlag=ATAG_CMDLINE;
    strcpy(ptAtag->tTagType.tCmdline.c,buf);
    return (atag *)((long *)tAddr+ptAtag->tHeader.wSize);
}
atag *set_tag_none(atag * tAddr)
{
    atag *ptAtag=(atag *)tAddr;
    ptAtag->tHeader.wSize=0;
    ptAtag->tHeader.wFlag=ATAG_NONE;
    return (atag *)((long *)tAddr+sizeof(tag_header));  
}
atag *show_tag(atag * tAddr)
{
    int i;
    atag *ptShow=(atag *)tAddr;
    long *p=NULL;
    for(;ATAG_NONE!=ptShow->tHeader.wFlag;ptShow=(atag *)((byte *)ptShow+(4*ptShow->tHeader.wSize)))
    {//becase the size is Assign(4)
        p=(long *)(&ptShow->tTagType);
        printf("Flag Size =%x\r\n",ptShow->tHeader.wSize);
        printf("Flag Core =%x\r\n",ptShow->tHeader.wFlag);
        switch(ptShow->tHeader.wFlag)
        {
            case ATAG_CORE:
                printf("Flag=0x%x,PageSize=0x%x,Rootdev=0x%x\r\n",p[0],p[1],p[2]);
                break;
            case ATAG_MEM:
                printf("Memory base=0x%x,Size=0x%x\r\n",p[1],p[0]);
                break;
            case ATAG_SERIAL:
                break;
            case ATAG_CMDLINE:
                printf("CommandLine=%s\r\n",ptShow->tTagType.tCmdline.c);
                break;
        }
    }
    return (atag *)(tAddr);
}
static int main(int argc, char *argv[])
{
    typedef void (*kernel_entry)(int,int,UINT32);
    enum load_style
    {
        flash,serial,tftp
    }tLoadStyle=flash;
    int i;
    char *fmt;
    char *pKernelName;
    char *pNfsParam;
    char chCommandLine[1024]={0};
    bool bIsShow    =false;
    bool bNfsSupport=false;
    const uint32 tag_base=(MEM_BASE+0x100);
    atag *tCurser=NULL;
    volatile kernel_entry pKernelEntry=(kernel_entry)(MEM_BASE+KERNEL_OFFSET);

    for (i = 1; i < argc; ++i)
    {
        fmt = argv[i];
        switch (fmt[0])
        {
        case '-':
            fmt[0]=fmt[1];//cp the param
            i--;
            break;
        case 't'://file name along
        case 'T':
            tLoadStyle=tftp;
            pKernelName=argv[++i];
            break;
        case 'n': //nfs root mount
        case 'N':
            bNfsSupport=true;
            pNfsParam  =argv[++i];
            break;
        case 's': //serial load
        case 'S':
            tLoadStyle=serial;
        case 'r'://ram disk boot
        case 'R':
            break;
        case 'v':
        case 'V':
            bIsShow=true;
            break;
        }
    }
    switch(tLoadStyle)
    {
        case flash:
            break;
        case serial:
            v_bios_serial_load((void *)(MEM_BASE+KERNEL_OFFSET));
            break;
        case tftp:
            break;
    }
    printf("booting the kernel\r\n");
    strcpy(chCommandLine,"noinitrd root=dev/mtdblock2 init=linuxrc console=ttySAC0,115200");
    tCurser=(atag *)(tag_base);
    tCurser=set_tag_core(tCurser);
    tCurser=set_tag_mem(tCurser);
    //tCurser=set_tag_serial(tCurser);
    tCurser=set_tag_cmdline(tCurser,chCommandLine);
    tCurser=set_tag_none(tCurser);
    if(bIsShow)
    {
        show_tag((atag *)tag_base);
        return false;
    }
    //IrqDisable();
    pKernelEntry(0,MACHINE_ID,tag_base);
    return true;
}

INSTALLAPP(boot, main);
