#include "Typedef.h"
#include "util.h"
#include "s3c24xxreg.h"
#include "SysCall.h"
#include "malloc.h"

struct free_list_node
{
    struct free_list_node *prev;
    struct free_list_node *next;
};
struct mem_desc
{
    int  wCurrentSize;
    bool bHaveUsed;
    struct free_list_node list;
    byte ch[1];
};


static struct free_list_node *g_ptListFirst;
static struct free_list_node *g_ptListTail;

static long  g_tMemoryCusor;

bool remove_list(struct free_list_node *p)
{
    p->prev->next=p->next;
    p->next->prev=p->prev;
    return true;
}
bool add_list(struct free_list_node p)
{
    p.next=NULL;
    p.prev=g_ptListTail;
    g_ptListTail=&p;
    return true;
}


void * (malloc)(size_t n)
{
    struct mem_desc *p;
    struct free_list_node *cursor;
    unsigned int *pLen;
    for (cursor =g_ptListFirst; cursor!=g_ptListTail;cursor=cursor->next)
    {
        pLen=(int *)(&cursor)-2;
        if(n==pLen[0])//match the data type
        {
            pLen[1]=true;
            remove_list(cursor);
            return (void *)(&pLen[4]);
        }
    }
    if((g_tMemoryCusor+sizeof(struct mem_desc)+n)>=BH_START_ADDRESS_MEM)
    {
        return NULL;//No Memory At All
    }
    p=(struct mem_desc *)g_tMemoryCusor;//now alloc a new memory
    p->wCurrentSize=n;
    p->bHaveUsed   =true;
    g_tMemoryCusor =g_tMemoryCusor+sizeof(struct mem_desc)+n;
    return (void *)(&(p->ch));
}
void (free)(void *p)
{
    struct mem_desc *vtp;
    vtp=(struct mem_desc *)((unsigned char *)p-(sizeof(struct mem_desc)-1));
    add_list(vtp->list);
}

void init(void * addr,size_t len)
{
    UINT32  wHeapBase;
    wHeapBase=addr-(UINT32)len;//all is 16M assign
    g_tMemoryCusor=wHeapBase; //Init The Memory Base
    printf("heap base=0x%x,size=0x%x\r\n",wHeapBase,len);
}
bool init_heap(void)
{
    init((void *)BH_START_ADDRESS_MEM,0x01000000);//16M
    return true;
}

INSTALLINIT(heap,init_heap);//heap is also a device