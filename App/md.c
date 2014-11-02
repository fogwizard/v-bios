#include "Typedef.h"
#include "util.h"
#include "SysCall.h"
#include "stdio.h"
#include "string.h"

static void usase(void)
{
    printf("Use md -r/w address len/dat\r\n");
}
static int main(int argc, char *argv[])
{
    int i=0;
    int ReadLen=0;
    byte c;
    UINT32 Addr;
    if ((4 != argc))
    {
        usase();
    }
    if (0 == strcmp("-w", argv[1]))
    {
        Addr = atoi(argv[2]);
        c      = atoi(argv[3]);
        WriteByte(Addr, c);
        printf("Write %d addr to 0x[%x]\r\n", Addr, c);
    }
    else if (0 == strcmp("-r", argv[1]))
    {
        Addr   = atoi(argv[2]);
        ReadLen = atoi(argv[3]);
        for (i = 0; i < ReadLen; i++)
        {
            c = ReadByte(Addr++);
            printf("%x,", c);
        }
    }
    return true;
}

INSTALLAPP(md, main);