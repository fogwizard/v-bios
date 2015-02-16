src+=boot_linux.c cd.c ls.c flashrw.c help.c md.c reboot.c load.c tftp.c TestMalloc.c
obj:=$(src:.c=.o)
$(obj): $(src) 
	$(CC) -c $(CCFLAG) $^
all: $(obj)
	$(LD) -r $(LDFLAG) $^ -o buildin.o
