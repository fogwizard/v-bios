src+=boot_linux.c
obj:=$(src:.c=.o)
$(obj): $(src) 
	$(CC) -c $(CCFLAG) $^
all: $(obj)
	$(LD) -r $(LDFLAG) $^ -o buildin.o
