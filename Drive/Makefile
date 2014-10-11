obj+=Uart/buildin.o Misc/buildin.o
all: 
	@make -C Uart all
	@make -C Misc all
	$(LD) -r $(LDFLAG) $(obj) -o buildin.o
