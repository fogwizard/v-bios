obj+=Uart/buildin.o Misc/buildin.o Flash/buildin.o
all: 
	@make -C Uart  all
	@make -C Misc  all
	@make -C Flash all
	$(LD) -r $(LDFLAG) $(obj) -o buildin.o
