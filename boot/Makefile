src+=head.s Common/main.c ../Drive/Uart/kermit.c ../Drive/Uart/Uart.c ../Drive/Misc/misc.c ../Drive/Flash/flash.c
obj+=head.o main.o kermit.o Uart.o misc.o flash.o
all: v-bios-th.elf v-bios-th.bin v-bios-th.dis

$(obj): $(src)
	$(CC) $(CCFLAG) -c $^ 
v-bios-th.elf: $(obj)
	$(LD) $(LDFLAG) -Tth.lds  $^ -o $@
v-bios-th.bin: v-bios-th.elf
	 $(CROSS_COMPILE)objcopy -O binary -S $< $@
v-bios-th.dis: v-bios-th.elf
	$(CROSS_COMPILE)objdump -d $< > $@
clean:
	rm -f v-bios-th.elf v-bios-th.bin v-bios-th.dis
