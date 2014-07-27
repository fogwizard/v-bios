#include "common.h"
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
				printf("Press 0 or 1 please\n");
				break;
		}
	}

}
#define THRunBH() do{*BHAddress();}while(0) 
void main(void)
{
	static void (*BHaddress)(void)=0x30100000;
	THInitClock();
	THInitUart();
	THInitFlash();
	THLoadBH();
	THRunBH();
}
