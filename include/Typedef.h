typedef unsigned char BYTE,Byte,byte,uchar,uint8_t;
typedef unsigned int  WORD,uint,uint32_t,UINT32;
typedef int  bool,BOOL,Bool;
typedef unsigned long ULONG,ulong;

typedef enum
{
  fsm_rt_err=-1,
  fsm_rt_cpl=0,
  fsm_rt_on_going=1
}fsm_rt_t;
typedef union
{
  long l;
  unsigned long ul;
  int  i;
  unsigned int ui;
  BYTE c[4];
}UL,UI;



#define NULL  (0)
#define false (0)
#define true  (!False)
#define TRUE  true 
#define FALSE false
#define True  true 
#define False false

