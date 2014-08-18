#include "common.h"
#define Readl() 0x50
#define Writel(addr,n) do{*((unsigned long *)addr)=n;}while(0)
void SendByte(unsigned char n)
{
	while(Readl()&0x02);
	Writel(0x50000020,n);
}	
int ShowString(const char *dat)
{
	int i;
	for(i=0;i<10;i++){

	}
}

int LoadFromFlash(void)
{

}
int LoadFromUart(void)
{

}

unsigned char UartGetChar(char n)
{
	return 'n';
}
void THLoadBH(void)
{
	char ch;
	ShowString("V-bios Rev 0.0 \n");
	ShowString("Press 0 boot from the Flash\n");
	ShowString("Press 1 boot from the Uart \n");
	while ( 1 )
	{
	    ch=UartGetChar(0);
		switch ( ch )
		{
		    case '0' :
		        LoadFromFlash();
		        break;
		    case '1' :
		        LoadFromUart();
		        break;
		    default:
				ShowString("Press 0 or 1 please\n");
				break;
		}
	}

}

void THInitClock(void)
{
}
void THInitnUart(void)
{
}
void THInitFlash(void)
{
}


#define THRunBH() do{((void (*)())x)();}while(0) 
int main(void)
{
	long x=0x30100000;
	THInitClock();
	THInitnUart();
	THInitFlash();
	THLoadBH();
	THRunBH();
	return 0;
}
