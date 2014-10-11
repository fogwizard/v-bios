src+=misc.c
obj:=$(src:.c=.o)
$(obj): $(src)
	$(CC) $(CCFLAG) -c $^ 
all: $(obj)
	$(LD) $(LDFLAG) -r $^ -o buildin.o