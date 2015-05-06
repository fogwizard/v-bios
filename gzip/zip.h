struct struct_zip{
	unsigned char magic1;
	unsigned char magic2;
	unsigned char compress_meth;//should be 0x08
	unsigned char flag;//bit value
};
