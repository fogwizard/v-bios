-include .config
version=0.0
USER_HOME=$(shell echo $HOME)
TOP_DIR=$(shell pwd)
SubDir =$(shell ls -R |grep /)
SubDirS=$(subst :,/,$(SubDir))
SourceOBJ=$(foreach dir,$(SubDirS),$(wildcard $(dir)*.o))
MENUCONFIG=./build/menuconfig/menuconfig
ARCH=arm
nCPU=s3c2440
CROSS_COMPILE=arm-linux-
CONFIG_TH_START_ADDRESS_MEM=0x00000000
CONFIG_BH_START_ADDRESS_MEM=0x33f80000
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
AS=$(CROSS_COMPILE)as
LDFLAG=-m armelf_linux_eabi
CCFLAG=-ffreestanding -nostdinc -nostdlib -fno-builtin -DGBIOS_VER_MAJOR=2 -DGBIOS_VER_MINOR=0 -mno-thumb-interwork  -march=armv4t -mabi=aapcs-linux 
export ARCH nCPU CROSS_COMPILE AS CC LD TOP_DIR CONFIG_TH_START_ADDRESS_MEM CONFIG_BH_START_ADDRESS_MEM LDFLAG CCFLAG
all: .config BH TH
TH: 
	@make -C boot all
	@echo
clean:
	@echo   $(SourceOBJ)
	rm -rf $(SourceOBJ)
	@make -C boot clean
disclean:
