#include "Typedef.h"
#include "s3c24xxreg.h"
#include "Uart.h"
#include "util.h"
#include "flash.h"

struct 
{
	UINT32 PageSize;
	UINT32 BlockSize;
	UINT32 DataRegister;
	UINT32 AddressRegister;
	UINT32 CommandRegister;

}g_tFlashObj;

static const byte c_chNandIds[]=\
{
	0x33,0x35,0x36,0x39,0x43,0x45,0x46,0x49,0x53,0x55,
	0x56,0x59,0x71,0x72,0x73,0x74,0x75,0x76,0x78,0x79
};


bool nand_ready(void);

static inline byte nand_read_byte(void)
{
	return ReadByte(NAND_CTRL_BASE+ NF_DATA);
}


void nand_cmd(void)
{


}
bool is_power2(UINT32 n)
{
	return (0==(n&(n-1)))?true:false;
}

bool find_ids(byte chDeviceId)
{
	byte i;
	for (i = 0; i < 20; ++i)
	{
		if(chDeviceId==c_chNandIds[i])
		{
			return true;
		}
	}
	return false;
}
bool init_flash(void)
{
	BYTE chVeterId,chDeviceId,chExId;
	g_tFlashObj.AddressRegister=NAND_CTRL_BASE+NF_ADDR;
	g_tFlashObj.DataRegister   =NAND_CTRL_BASE+NF_DATA;
	g_tFlashObj.CommandRegister=NAND_CTRL_BASE+NF_CMMD;
	WRITESHORT(NAND_CTRL_BASE+NF_CONF,0x2440);
	WRITESHORT(NAND_CTRL_BASE+NF_CONT,0x01);//enable the Nand Flash
	if(false==nand_ready())//Not Rdy
	{
		ShowString("Flash Init Error\r\n");
	}
	nand_cmd();
	chVeterId =nand_read_byte();
	chDeviceId=nand_read_byte();
	Uart0PrintChar(chVeterId);
	Uart0PrintChar(',');
	Uart0PrintChar(chDeviceId);
	Uart0PrintChar('\r');
	Uart0PrintChar('\n');
	if(find_ids(chDeviceId))
	{
		g_tFlashObj.PageSize=512;
		g_tFlashObj.BlockSize=KB(16);
	}
	else
	{
		chExId=nand_read_byte();
		chExId=nand_read_byte();
		g_tFlashObj.PageSize =(KB(1))<<(chExId&0x03);
		g_tFlashObj.BlockSize=(KB(64))<<((chExId>>4)&0x03);
	}
	if(is_power2(g_tFlashObj.BlockSize)&&is_power2(g_tFlashObj.PageSize))
	{
		ShowString("Flash Size OK\r\n");
		return true;
	}
	return false;
}
bool nand_ready(void)
{
	WORD i;
	for (i = 0; i < 0xffffff; ++i)
	{
		if((0x01&ReadByte(NAND_CTRL_BASE+NF_STAT)))
		{
			return true;
		}
	}
	return false;
}


