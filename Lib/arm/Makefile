src_asm+=lib1funcs.S
obj_asm:=$(src_asm:.S=.o)
src+=div0.c
obj:=$(src:.c=.o)

$(obj_asm): $(src_asm)
	$(CC) -c $(CCFLAG) -D__ASSEMBLY__ $^ -o $@
$(obj): $(src) 
	$(CC) -c $(CCFLAG) $^ -o $@
all: $(obj_asm) $(obj)
	$(LD) $(LDFLAG) -r $^ -o buildin.o
	
