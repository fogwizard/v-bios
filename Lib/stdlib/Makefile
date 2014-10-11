src+=stdio.c stdlib.c string.c
obj:=$(src:.c=.o)
$(obj): $(src) 
	$(CC) -c $(CCFLAG) $^
all: $(obj)
	$(LD) $(LDFLAG) -r $^ -o buildin.o
	
