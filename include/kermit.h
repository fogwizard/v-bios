#define MARK_START 0x01
#define MARK_EXIT  0x03

#define KERMIT_TYPE_DATA  'D'
#define KERMIT_TYPE_SEND  'S'
#define KERMIT_TYPE_ACK   'Y'
#define KERMIT_TYPE_NACK  'N'
#define KERMIT_TYPE_BREAK 'B'

#define KERMIT_KEY_SPASE 0x20
#define KERMIT_KEY_SHARP 0x23
#define KERMIT_KEY_TERM  0x0d

#define KERMIT_BUF_LEN 128

typedef struct
{
  BYTE len;
  BYTE seq;
  BYTE type;
  BYTE check;
  BYTE check_have_encode;
  BYTE valid_data_len;
  WORD spase;
  BYTE buf[KERMIT_BUF_LEN];
}TAG_KERMIT;

#define KERM_ENCODE(c) (c+KERMIT_KEY_SPASE)
#define KERM_DECODE(c) (c-KERMIT_KEY_SPASE)
