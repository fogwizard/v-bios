#include "Typedef.h"
#include "util.h"
#include "SysCall.h"
#include "stdio.h"

void ShowCommand(void);

static int main(int argc,char *argv[])
{
	ShowCommand();
  return 0;
}
void ShowCommand(void)
{
	TagSysCall *p;
	printf("Support the command like this:\r\n");
	for(p=SYSCALL_BEGIN;p<SYSCALL_END;p++)
	{
		printf("%s\r\n",p->Name);
	}
}

INSTALLAPP(help,main);
