all: v-bios-th.elf
source_c=head.s Common/main.c
obj_c=   head.o main.o

$(obj_c): $(source_c)
	$(CC) $(CCFLAG) -c $^ 

v-bios-th.elf: $(obj_c)
	$(LD) $(LDFLAG) -T th.lds  $^ -o $@
