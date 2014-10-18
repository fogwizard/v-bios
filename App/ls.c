#include "Typedef.h"
#include "util.h"
#include "SysCall.h"
#include "stdio.h"
#include "flash.h"

bool test(parttition_info_t * pPartion)
{
    printf("name=%s\r\n",pPartion->name);
    printf("addr=%d\r\n",pPartion->start_addr);
    printf("Len= %d\r\n",pPartion->len);

}
static int main(int argc, char *argv[])
{
    int i;
    byte buf[4]={0x76,0x2d,0x62,0x68};
    printf("ls.c is Running\r\n");
    i=memcmp(c_VbiosMagic,buf,4);
    test((parttition_info_t *)&c_tPart.bh);
    return 0;
}

INSTALLAPP(ls, main);
