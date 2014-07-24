#include <plamform.h>
static void SysInit(void); 
static void VfsInit(void); 
static void ExecShell(void); 

char chByteCmdbuf[256];

static int main(void)
{
	SysInit();
	VfsInit();
	ExecShell();
}
static void SysInit(void)
{

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

