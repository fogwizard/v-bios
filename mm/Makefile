src+=malloc.c
obj:=$(src:.c=.o)
$(obj): $(src) 
	$(CC) -c $(CCFLAG) $^
all: $(obj)
	$(LD) $(LDFLAG) -r $^ -o buildin.o
