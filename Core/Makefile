src+=SysCall.c net_core.c
obj:=$(src:.c=.o)
$(obj): $(src) 
	$(CC) -c $(CCFLAG) $^
all: $(obj)
	$(LD) -r $(LDFLAG) $^ -o buildin.o
