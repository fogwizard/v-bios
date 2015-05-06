struct struct_zip{
	unsigned char magic1;
	unsigned char magic2;
	unsigned char compress_meth;//should be 0x08
	unsigned char flag;//bit value
	unsigned char t1;//Unix time
	unsigned char t2;
	unsigned char t3;
	unsigned char t4;
};
int do_gzip(const char *);
int do_gunzip(const char *);
