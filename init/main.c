#include "Typedef.h"
#include "plamform.h"
#include "util.h"
#include "flash.h"
static void SysInit(void); 
static void VfsInit(void); 
static void ExecShell(void); 

char chByteCommandLine[CMD_ARG_MAX][32];

int main(void)
{
	SysInit();
	VfsInit();
	ExecShell();
}
static void DisableWatchDog(void)
{

}
static void InitInterrupt(void)
{

}
static void InitClock(void)
{

}
static void InitUart0(void)
{

}
static void InitEth(void)
{

}


static void SysInit(void)
{
	DisableWatchDog();
	InitInterrupt();
	InitClock();
	InitUart0();
   	InitEth();
   	init_flash();
}
static void VfsInit(void)
{

}
static void ExecShell(void)
{
	int argc=0;
	char *argv[CMD_ARG_MAX];
	printf("PageSize=%d,BlockSize=%d\r\n",g_tFlashObj.PageSize,g_tFlashObj.BlockSize);
	printf("Botton Half Running\r\n");
	printf("Support %d Args\r\n",CMD_ARG_MAX);
	while(1)
	{
		argc=ReadCmd((char *)chByteCommandLine,argv);
		argc=ExecCmd(argc,argv);
	}
}

