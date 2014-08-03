all: v-bios-th.elf v-bios-th.bin v-bios-th.dis
source_c=head.s Common/main.c
obj_c=   head.o main.o

$(obj_c): $(source_c)
	$(CC) $(CCFLAG) -c $^ 

v-bios-th.elf: $(obj_c)
	$(LD) $(LDFLAG) -T th.lds  $^ -o $@
v-bios-th.bin: v-bios-th.elf
	 $(CROSS_COMPILE)objcopy -O binary -S $< $@
v-bios-th.dis: g-bios-th.elf
	$(CROSS_COMPILE)objdump -d $< > $@

