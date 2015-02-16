typedef unsigned char BYTE,Byte,byte,uchar,uint8_t;
typedef unsigned int  WORD,word,uint,uint32_t,UINT32,uint32,size_t,__u32,u32;
typedef int  bool,BOOL,Bool,__s32;
typedef unsigned long ULONG,ulong;
typedef unsigned short uint16,u16;
typedef short int16;

typedef enum
{
  fsm_rt_err=-1,
  fsm_rt_cpl=0,
  fsm_rt_on_going=1,
  fsm_rt_back
}fsm_rt_t;
typedef union
{
  long l;
  unsigned long ul;
  int  i;
  unsigned int ui;
  BYTE c[4];
}UL,UI;

typedef struct 
{
	UINT32 PageSize;
	UINT32 BlockSize;
	UINT32 DataRegister;
	UINT32 AddressRegister;
	UINT32 CommandRegister;
}flash_attribute_t;

typedef struct 
{
  char *name;
  UINT32 start_addr;
  UINT32 len;
}parttition_info_t;

typedef struct 
{
    parttition_info_t th;
    parttition_info_t bh;
    parttition_info_t kl;
}parttition_table_t;


#define NULL  (0)
#define false (0)
#define true  (!False)
#define TRUE  true 
#define FALSE false
#define True  true 
#define False false

#define __VOLATILE__ volatile

