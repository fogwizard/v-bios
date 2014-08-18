all: v-bios-th.elf v-bios-th.bin v-bios-th.dis
source_c=head.s Common/main.c
source_o=head.o main.o

$(source_o): $(source_c)
	$(CC) $(CCFLAG) -c $^ 
v-bios-th.elf: $(source_o)
	$(LD) $(LDFLAG) -Tth.lds  $^ -o $@
v-bios-th.bin: v-bios-th.elf
	 $(CROSS_COMPILE)objcopy -O binary -S $< $@
v-bios-th.dis: v-bios-th.elf
	$(CROSS_COMPILE)objdump -d $< > $@
clean:
	rm -f v-bios-th.elf v-bios-th.bin v-bios-th.dis
