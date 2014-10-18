// standard nand commands
#define NAND_CMMD_READ0		0
#define NAND_CMMD_READ1		1
#define NAND_CMMD_RNDOUT	5
#define NAND_CMMD_PAGEPROG	0x10
#define NAND_CMMD_READOOB	0x50
#define NAND_CMMD_ERASE1		0x60
#define NAND_CMMD_STATUS		0x70
#define NAND_CMMD_STATUS_MULTI	0x71
#define NAND_CMMD_SEQIN		0x80
#define NAND_CMMD_RNDIN		0x85
#define NAND_CMMD_READID	0x90
#define NAND_CMMD_ERASE2	0xd0
#define NAND_CMMD_RESET		0xff


#define NAND_CMMD_READSTART	    0x30
#define NAND_CMMD_RNDOUTSTART	0xE0
#define NAND_CMMD_CACHEDPROG	0x15


#define NAND_CMMD_DEPLETE1      0x100
#define NAND_CMMD_DEPLETE2      0x38
#define NAND_CMMD_STATUS_MULTI  0x71
#define NAND_CMMD_STATUS_ERROR  0x72
#define NAND_CMMD_STATUS_ERROR0 0x73
#define NAND_CMMD_STATUS_ERROR1 0x74
#define NAND_CMMD_STATUS_ERROR2 0x75
#define NAND_CMMD_STATUS_ERROR3 0x76
#define NAND_CMMD_STATUS_RESET  0x7f
#define NAND_CMMD_STATUS_CLEAR  0xff

#define NAND_CMMD_NONE		-1

extern volatile flash_attribute_t g_tFlashObj;
extern const    parttition_table_t c_tPart;

extern const char c_VbiosMagic[];//magic

extern bool init_flash(void);

extern v_bios_flash_load    (parttition_info_t * pPartion,void *);
extern v_bios_flash_download(parttition_info_t * pPartion,void *);
extern byte read_one_byte_from_flash(UINT32 addr);
extern bool write_one_byte_to_flash(UINT32 addr,byte dat);


