-include .config
version=0.0
USER_HOME=$(shell echo $HOME)
TOP_DIR=$(shell pwd)
SubDir =$(shell ls -R |grep /)
SubDirS=$(subst :,/,$(SubDir))
SourceOBJ=$(foreach dir,$(SubDirS),$(wildcard $(dir)*.o))
buildin_obj=buildin.o
MENUCONFIG=./build/menuconfig/menuconfig
ARCH=arm
nCPU=s3c2440
CROSS_COMPILE=arm-linux-
CONFIG_TH_START_ADDRESS_MEM=0x00000000
CONFIG_BH_START_ADDRESS_MEM=0x33000000
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
AS=$(CROSS_COMPILE)as
LDFLAG=-m armelf_linux_eabi
CCFLAG=-ffreestanding -nostdinc -nostdlib -fno-builtin -DBH_START_ADDRESS_MEM=$(CONFIG_BH_START_ADDRESS_MEM) -DVBIOS_VER_MAJOR=0 -DVBIOS_VER_MINOR=0 -mno-thumb-interwork  -march=armv4t -mabi=aapcs-linux -O2 -mpoke-function-name -I $(TOP_DIR)/include
export ARCH nCPU CROSS_COMPILE AS CC LD TOP_DIR CONFIG_TH_START_ADDRESS_MEM CONFIG_BH_START_ADDRESS_MEM LDFLAG CCFLAG buildin_obj
BhSubDir=\
arch \
mm \
Core \
Drive \
init \
Lib \
App

all: .config TH BH
TH: 
	@make clean
	@make -C boot all
	@echo
BH: v-bios-bh.elf v-bios-bh.bin v-bios-bh.dis

v-bios-bh.elf: 
	@for dir in $(BhSubDir); do make -C $$dir all; done
	$(LD) $(LDFLAG) -T bh.lds -Ttext $(CONFIG_BH_START_ADDRESS_MEM) boot/head.o mm/buildin.o Core/buildin.o Drive/buildin.o init/buildin.o Lib/buildin.o App/buildin.o -o $@
v-bios-bh.bin: v-bios-bh.elf
	 $(CROSS_COMPILE)objcopy -O binary -S $< $@
v-bios-bh.dis: v-bios-bh.elf
	$(CROSS_COMPILE)objdump -D $< > $@
	echo "123456" | sudo -S cp v-bios-bh.bin ./boot/v-bios-th.bin  /media/sf_upfile/
	
clean:
	@echo   $(SourceOBJ)
	rm -rf $(SourceOBJ)
	@make -C boot clean
	rm -rf TH BH v-bios-bh.bin v-bios-bh.elf v-bios-bh.dis
disclean:
