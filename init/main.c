#include <plamform.h>
static void SysInit(void); 
static void VfsInit(void); 
static void ExecShell(void); 

char chByteCmdbuf[256];
char chByteCommandLine[10][32];

static int main(void)
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
	while(1){
		ReadCmd(chByteCmdbuf);
		ExecCmd(chByteCmdbuf);
	}
}

