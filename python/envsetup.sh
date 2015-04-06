#########################################################################
# File Name: envsetup.sh
# Author: ma6174
# mail: ma6174@163.com
# Created Time: 2015年03月06日 星期五 19时15分53秒
#########################################################################
#!/bin/bash
TOP=$(pwd)
echo $TOP
export DT_CC=$TOP/prebuilts/gcc/linux-x86/arm/arm-eabi-4.8/bin/arm-eabi-gcc
export DT_INCLUDE=" -E -nostdinc -I$TOP/kernel/arch/arm/boot/dts -I$TOP/kernel/arch/arm/boot/dts/include -undef -D__DTS__ -x assembler-with-cpp "
