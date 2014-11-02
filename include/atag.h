#define MACHINE_ID    168
#define MEM_BASE      0x30000000
#define KERNEL_OFFSET 0x00008000

#define ATAG_NONE 0x00000000
typedef struct 
{
    UINT32 wSize;
    UINT32 wFlag;
}tag_header;

#define ATAG_CORE 0x54410001
typedef struct 
{
    UINT32 wFlag;
    UINT32 wPageSize;
    UINT32 wRootDev;
}tag_core;

#define ATAG_MEM 0x54410002
typedef struct 
{
    UINT32 wSize;
    UINT32 wStart;
}tag_mem;

#define ATAG_VIDEOTEXT 0x54410003
typedef struct 
{
    byte   chBx;
    byte   chBy;
    uint16 hwVideoPage;
    byte   chVideoMode;
    byte   chVideoCols;
    uint16 hwVideoEgaBx;
    byte   chVideoLine;
    byte   chIsVGA;
    uint16 hwVideoPoints;
}tag_vidiotext;

#define ATAG_RAMDISK 0x54410004
typedef struct 
{
    UINT32 wFlags;
    UINT32 wSize;
    UINT32 wStart;
}tag_ramdisk;

#define ATAG_INITRD  0x54410005
#define ATAG_INITRD2 0x54420005
typedef struct 
{
    UINT32 wStart;
    UINT32 wSize;
}tag_initrd;

#define ATAG_SERIAL 0x54410006
typedef struct 
{
    UINT32 wLow;
    UINT32 wHigh;
}tag_serial;

#define ATAG_REVISION 0x54410007
typedef struct 
{
    UINT32 wRev;
}tag_revision;

#define ATAG_VIDEOLFB 0x54410008
typedef struct 
{
    uint16 hwFbWidth; 
    uint16 hwFbHeight;
    uint16 hwFbDepth;
    uint16 hwFbLineLength;
    uint32 hwFbBase;
    uint32 hwFbSize; 
    byte   chRedSize;
    byte   chRedPos;
    byte   chGreenSize;
    byte   chGreenPos;
    byte   chBlueSize;
    byte   chBluePos;
    byte   chRsvdSize;
    byte   chRsvdPos;
}tag_videolfb;

#define ATAG_CMDLINE 0x54410009
typedef struct 
{
    char c[8];
}tag_cmdline;

#define ATAG_MEMCLK 0x41000402
typedef struct 
{
    UINT32 wMemClk;
}tag_memclk;

typedef struct 
{
    tag_header tHeader;
    union
    {
        tag_core      tCore;
        tag_mem       tMem;
        tag_vidiotext tVideoText;
        tag_serial    tSerial;
        tag_videolfb  tVideoLfb;
        tag_initrd    tInitrd;
        tag_ramdisk   tRamdisk;
        tag_revision  tRevision;
        tag_cmdline   tCmdline;
    }tTagType;
}atag;
