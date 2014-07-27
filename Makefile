-include .config
version=0.0
USER_HOME=$(shell echo $HOME)
TOP_DIR=$(shell pwd)
MENUCONFIG=./build/menuconfig/menuconfig
ARCH=arm
CROSS_COMPILE=arm-linux-
CONFIG_START_ADDRESS_MEM=0x30100000
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
AS=$(CROSS_COMPILE)as
export ARCH CROSS_COMPILE AS CC LD CONFIG_START_ADDRESS_MEM
all: .config BH TH
TH: 
	@make -C boot all
	@echo
clean:
disclean:
