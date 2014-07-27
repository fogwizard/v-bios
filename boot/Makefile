all: th.elf
th.elf: $(SUB_DIR)
	$(LD) $(LDFLAS) -T $(ARCH)/th.lds -TText $(CONFIG_START_ADDRESS_MEM) $^ -o $@
