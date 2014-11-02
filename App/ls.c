#include "Typedef.h"
#include "util.h"
#include "SysCall.h"
#include "stdio.h"
#include "flash.h"

extern volatile flash_attribute_t g_tFlashObj;
extern volatile const parttition_table_t c_tPart;

bool test(parttition_info_t * pPartion)
{
    printf("name=%s\r\n",pPartion->name);
    printf("addr=%d\r\n",pPartion->start_addr);
    printf("Len= %d\r\n",pPartion->len);

}
static int main(int argc, char *argv[])
{
    printf("ls.c is Running\r\n");
    test((parttition_info_t *)&c_tPart.bh);
    return 0;
}

INSTALLAPP(ls, main);
