#include "common.h"
int ShowString(const char *dat)
{
	int i;
	for(i=0;i<10;i++){

	}
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
#define THRunBH() do{((void (*)())x)();}while(0) 
void main(void)
{
	long x=0x30100000;
	THInitClock();
	THInitUart();
	THInitFlash();
	THLoadBH();
	THRunBH();
}
