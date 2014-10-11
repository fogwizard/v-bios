#include "Typedef.h"
#include "plamform.h"
#include "util.h"
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
}
static void VfsInit(void)
{

}
static void ExecShell(void)
{
	int argc=0;
	char *argv[CMD_ARG_MAX];
	printf("Botton Half Running\r\n");
	printf("Support %d Args\r\n",CMD_ARG_MAX);
	while(1)
	{
		argc=ReadCmd((char *)chByteCommandLine,argv);
		printf("argc=%d,",argc);
		printf("argv[0]=[%s],",argv[0]);
		printf("argv[1]=[%s],",argv[1]);
		printf("argv[2]=[%s],",argv[2]);
		printf("argv[3]=[%s],",argv[3]);
		printf("argv[4]=[%s]\r\n",argv[4]);
		argc=ExecCmd(argc,argv);
		printf("return value=%d,",argc);
	}
}

