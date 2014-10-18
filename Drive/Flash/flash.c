#include "Typedef.h"
#include "s3c24xxreg.h"
#include "Uart.h"
#include "util.h"
#include "flash.h"

volatile flash_attribute_t  g_tFlashObj;
const    parttition_table_t c_tPart=\
{
	{
		"Top Harf"   ,KB(0x0),KB(4)
	},
	{
		"Botton Harf",KB(4),KB(64-4)
	},
	{
		"Kernel "    ,KB(256),(MB(4)-KB(256))
	}
};

const char c_VbiosMagic[]="v-bh";//0x762D6268

static const byte c_chNandIds[]=\
{
	0x33,0x35,0x36,0x39,0x43,0x45,0x46,0x49,0x53,0x55,
	0x56,0x59,0x71,0x72,0x73,0x74,0x75,0x76,0x78,0x79
};
static const byte c_chHex2dec[]=\
{
	'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','0'
};


static bool nand_ready(void);

//byte read_one_byte_from_flash(UINT32 addr);

//bool write_one_byte_to_flash(UINT32 addr,byte dat);


static bool is_large_page(void)
{
	if(g_tFlashObj.PageSize>=KB(1))
	{
		return true;
	}
	return false;
}

static inline byte nand_read_byte(void)
{
	return ReadByte(g_tFlashObj.DataRegister);
}
static inline void nand_write_byte(byte dat)
{
	WriteByte(g_tFlashObj.DataRegister,dat);
}
static inline void nand_write_cmd(byte dat)
{
	WriteByte(g_tFlashObj.CommandRegister,dat);
}
static inline void nand_write_addr(byte dat)
{
	WriteByte(g_tFlashObj.AddressRegister,dat);
}

static void nand_cmd(UINT32 nCmd, int nPageIndex, int nPageOffset)
{
	nand_write_cmd(nCmd);

	if (nPageOffset != -1)
	{
		nand_write_addr(nPageOffset & 0xff);

		if (is_large_page())
			nand_write_addr((nPageOffset >> 8) & 0xff);
	}

	if (nPageIndex != -1)
	{
		nand_write_addr(nPageIndex & 0xff);
		nand_write_addr((nPageIndex >> 8) & 0xff);
		
		// if ((nPageIndex >> 16) & 0xff)	 // fixme
			nand_write_addr((nPageIndex >> 16) & 0xff);
	}

	switch (nCmd)
	{
	case NAND_CMMD_READ0:
		if (ss_large_page())
			nand_write_cmd(NAND_CMMD_READSTART);
		break;

	default:
		break;
	}
	nand_ready();
}
static bool is_power2(UINT32 n)
{
	return (0==(n&(n-1)))?true:false;
}

static bool find_ids(byte chDeviceId)
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
static void hex2str(byte *Buf,byte chData)
{
	Buf[0]=c_chHex2dec[chData/16];
	Buf[1]=c_chHex2dec[chData%16];
	Buf[2]='\0';
}
bool init_flash(void)
{
	byte chVeterId,chChipId,chExId;
	byte buf[3];
	g_tFlashObj.AddressRegister=NAND_CTRL_BASE+NF_ADDR;
	g_tFlashObj.DataRegister   =NAND_CTRL_BASE+NF_DATA;
	g_tFlashObj.CommandRegister=NAND_CTRL_BASE+NF_CMMD;
	WRITESHORT(NAND_CTRL_BASE+NF_CONF,0x2440);
	WRITESHORT(NAND_CTRL_BASE+NF_CONT,0x01);//enable the Nand Flash
	nand_ready();//Not Rdy
	nand_write_cmd(NAND_CMMD_READID);
	nand_write_addr(0x0);
	nand_ready();
	chVeterId=nand_read_byte();
	chChipId =nand_read_byte();
	chExId   =nand_read_byte();
	chExId   =nand_read_byte();
	nand_read_byte();//Read 5 Cycle
	hex2str(buf,chVeterId);
	ShowString(buf);
	Uart0PrintChar(',');
	hex2str(buf,chChipId);
	ShowString(buf);
	ShowString("\r\n");
	if(find_ids(chChipId))
	{
		g_tFlashObj.PageSize=512;
		g_tFlashObj.BlockSize=KB(16);
	}
	else
	{

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
static bool nand_ready(void)
{
	WORD i;
	for (i = 0; i < 0xffffff; ++i)
	{
		if((0x01&ReadByte(NAND_CTRL_BASE+NF_STAT)))
		{
			return true;
		}
	}
	ShowString("Nand Wait Err\r\n");
	return false;
}
byte read_one_byte_from_flash(UINT32 addr)
{
	UINT32 PageAddr;
	UINT32 PageIndex;
	PageAddr =(addr>>11); //Page addr
	PageIndex=addr%2048;  //Offset
	nand_write_cmd(0x00);//read cmd
	nand_write_addr(0x0);
	nand_write_addr(0x0);
	nand_write_addr(PageAddr&0xff);
	nand_write_addr((0xff&(PageAddr>>8)));
	nand_write_addr((0xff&(PageAddr>>16)));
	nand_write_cmd(0x30);//read step2
	nand_ready();
	nand_write_cmd(0x05);//ramdom read
	nand_write_addr(PageIndex&0xff);
	nand_write_addr((PageIndex>>8)&0xff);
	nand_write_cmd(0xE0);
	return nand_read_byte();
}
bool write_one_byte_to_flash(UINT32 addr,byte dat)
{
	UINT32 PageAddr;
	UINT32 PageIndex;
	PageAddr =(addr>>11); //Page addr
	PageIndex=addr%2048;  //Offset
	nand_write_cmd(0x80);
	nand_write_addr(0x0);
	nand_write_addr(0x0);
	nand_write_addr(PageAddr&0xff);
	nand_write_addr((0xff&(PageAddr>>8)));
	nand_write_addr((0xff&(PageAddr>>16)));
	nand_write_byte(dat);
	nand_write_cmd(0x85);
	nand_write_addr(PageIndex&0xff);
	nand_write_addr((PageIndex>>8)&0xff);
	nand_write_byte(dat);
	nand_write_cmd(0x10);
	nand_ready();
	nand_write_cmd(0x70);
	return nand_ready();
}
bool erase_block(UINT32 BlockNum,UINT32 Len)
{
	UINT32 i;
	nand_write_cmd(0x60);
	nand_write_addr(0xff&(BlockNum<<6 ));
	nand_write_addr(0xff&(BlockNum>>2 ));
	nand_write_addr(0xff&(BlockNum>>10));
	nand_write_cmd(0xd0);
	nand_ready();
	for(i=0;i<0xffff;i++){
		i=i;
	}
	nand_write_cmd(0x70);
	nand_ready();
	return true;
}
bool check_bh_in_flash(UINT32 addr)
{
	byte c[4]={0};
	c[0]=read_one_byte_from_flash(addr+4);//flag
	c[1]=read_one_byte_from_flash(addr+5);//flag
	c[2]=read_one_byte_from_flash(addr+6);//flag
	c[3]=read_one_byte_from_flash(addr+7);//flag
	if((c[0]==c_VbiosMagic[0])&&(c[1]==c_VbiosMagic[1]))
	{
		if((c[2]==c_VbiosMagic[2])&&(c[3]==c_VbiosMagic[3]))
		{
			return true;
		}
	}
	return false;
}

bool v_bios_flash_load(parttition_info_t * pPartion,void *p)
{
	UINT32 i;
	UINT32 wReadAddr;
	UINT32 wDataLen;
	byte *pLoadAddr=(byte *)p;
	wReadAddr=pPartion->start_addr; // debug for address & Len
	wDataLen =pPartion->len;  	    //default 10K
	for (i = 0; i < wDataLen; ++i)
	{
		*pLoadAddr++=read_one_byte_from_flash((wReadAddr+i));
	}
	return check_bh_in_flash(wReadAddr);
}
bool v_bios_flash_download(parttition_info_t * pPartion,void *p)
{
	UINT32 i;
	UINT32 wWriteBase;
	UINT32 wDataLen;
	byte *pLoadAddr=(byte *)p;
	wWriteBase =pPartion->start_addr;
	wDataLen   =pPartion->len;
	//erase_block(0,1);//erase 256KB for bh where th is 4K,don't do that,bacause the the ops is block
	if(check_bh_in_flash(wWriteBase))
	{
		return false;
	}
	beep(1);
	for (i = 0; i <wDataLen; ++i)
	{
		write_one_byte_to_flash((wWriteBase+i),*pLoadAddr);
		pLoadAddr++;
	}
	beep(0);
	return true;
}


