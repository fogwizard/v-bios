typedef struct sock{
    /*
     * Now struct inet_timewait_sock also uses sock_common, so please just
     * don't add nothing before this first member (__sk_common) --acme
     */
  //  struct sock_common  __sk_common;
#define sk_node         __sk_common.skc_node
#define sk_nulls_node       __sk_common.skc_nulls_node
#define sk_refcnt       __sk_common.skc_refcnt
#define sk_tx_queue_mapping __sk_common.skc_tx_queue_mapping

#define sk_dontcopy_begin   __sk_common.skc_dontcopy_begin
#define sk_dontcopy_end     __sk_common.skc_dontcopy_end
#define sk_hash         __sk_common.skc_hash
#define sk_family       __sk_common.skc_family
#define sk_state        __sk_common.skc_state
#define sk_reuse        __sk_common.skc_reuse
#define sk_reuseport        __sk_common.skc_reuseport
#define sk_bound_dev_if     __sk_common.skc_bound_dev_if
#define sk_bind_node        __sk_common.skc_bind_node
#define sk_prot         __sk_common.skc_prot
#define sk_net          __sk_common.skc_net
   // socket_lock_t       sk_lock;
   // struct sk_buff_head sk_receive_queue;
    /*
     * The backlog queue is special, it is always used with
     * the per-socket spinlock held and requires low latency
     * access. Therefore we special case it's implementation.
     * Note : rmem_alloc is in this structure to fill a hole
     * on 64bit arches, not because its logically part of
     * backlog.
     */
    int         sk_rcvbuf;
 //   struct sk_filter __rcu  *sk_filter;
 //   struct socket_wq __rcu  *sk_wq;
    unsigned long       sk_flags;
  //  struct dst_entry    *sk_rx_dst;
  //  struct dst_entry __rcu  *sk_dst_cache;
    int         sk_sndbuf;
  //  struct sk_buff_head sk_write_queue;
    int         sk_wmem_queued;
    int         sk_gso_type;
    unsigned int        sk_gso_max_size;
    u16         sk_gso_max_segs;
    int         sk_rcvlowat;
    unsigned long           sk_lingertime;
  //  struct sk_buff_head sk_error_queue;
  //  struct proto        *sk_prot_creator;
    int         sk_err,
                sk_err_soft;
    unsigned short      sk_ack_backlog;
    unsigned short      sk_max_ack_backlog;
    __u32           sk_priority;
    struct pid      *sk_peer_pid;
    const struct cred   *sk_peer_cred;
    long            sk_rcvtimeo;
    long            sk_sndtimeo;
    void            *sk_protinfo;
    struct socket       *sk_socket;
    void            *sk_user_data;
  //  struct page_frag    sk_frag;
    __s32           sk_peek_off;
    int         sk_write_pending;
    __u32           sk_mark;
    u32         sk_classid;
    void            (*sk_state_change)(struct sock *sk);
    void            (*sk_data_ready)(struct sock *sk, int bytes);
    void            (*sk_write_space)(struct sock *sk);
    void            (*sk_error_report)(struct sock *sk);
 //   int         (*sk_backlog_rcv)(struct sock *sk,
 //                         struct sk_buff *skb);
    void                    (*sk_destruct)(struct sock *sk);
}tag_sock;

typedef struct 
{
    bool (*sendto)(void);
    bool (*recvfrom)(void);
    bool (*set_svr_addr)(void);
    bool (*set_ip_addr)(void);
    bool (*set_mac_addr)(void);
    bool (*read)(void);
    bool (*write)(void);
}tag_file_ops;

typedef struct
{
    UINT32 RegisterStart;
    UINT32 RegisterLen;
    UINT32 Nip;//ip addr
    UINT32 Sip;//server ip addr
    byte mac[6];
}tag_net_device;

int  sock_alloc(void);
bool sock_close(int fd);
bool sendto(int fd);
bool recvfrom(int fd);
bool regist_net_device(int MastID,tag_file_ops *ops);