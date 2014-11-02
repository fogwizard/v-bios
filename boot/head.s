.global TH_START
TH_START:
	b HandleReset
	.word 0x47420168
	.word HandleSwi
	.word HandleIabt
	.word HandleDabt
	.word HandleIrq
	.word HandleFiq
	
HandleReset:
	msr cpsr,#211
	ldr sp,=4096
	bl AsmInitWatchDog
	bl AsmInitClock
	bl AsmInitUart
	bl AsminitSDRAM
	bl main
	loop: b loop
AsmInitWatchDog:
	ldr r3,=0x53000000
	ldr r4,=0
	str r4,[r3]
	bx lr
AsmInitClock:
	ldr r3,=0x4c000000
	ldr r4,=0xffffff
	str r4,[r3]
	ldr r4,=0x007f021
	str r4,[r3,#4]
	ldr r4,=0x05
	str r4,[r3,#20]
	bx lr
AsmInitUart:
	ldr r2,=0x56000070
	ldr r3,=0x16faaa /*Selecdt Pin*/
	str r3,[r2]
	ldr r2,=0x56000078
	ldr r3,=0x7ff  /*Up resister*/
	str r3,[r2]
	ldr r2,=0x50000000
	ldr r3,=0x03  /*8Bit */
	str r3,[r2]
	ldr r2,=0x50000004
	ldr r3,=0x245 /*Set interrupt*/
	str r3,[r2]
	ldr r2,=0x50000008
	ldr r3,=0x0   /*Disable FIFO*/
	str r3,[r2]
	ldr r3,=0x50000028
	ldr r4,=0x1a /*Baud*/
	str r4,[r3]
	ldr r3,=0xffff
	ldr r4,=0x00
4:	sub r3,r3,#1 /*delay*/
	cmp r3,r4
	bne 4b;
	bx lr
AsminitSDRAM:
	ldr r0,=0x48000000/*Ram Ctl Base*/
	ldr r1,=RamctlConst
	ldr r3,=0
0:	ldr r2,[r1]
	str r2,[r0],#4
	add r1,r1,#4
	add r3,r3,#1
	cmp r3,#13
	bne 0b;
	ldr r0,=0xffff
1:	sub r0,r0,#1
	cmp r0,#0
	bne 1b
	ldr r0,=0x30000000
	ldr r1,=0x55AA55AA
2:	str r1,[r0]
	ldr r2,[r0]
	cmp r1,r2
	bne 2b
	bx lr

HandleUndefine: /*Now Use To The Magic*/
	b Hang;
HandleSwi:
	b Hang;
HandleIabt:
	b Hang;
HandleDabt:
	b Hang;
HandleIrq:
	b Hang;
HandleFiq:
	b Hang;
Hang:
	b Hang;
RamctlConst:
	.word 0x220dd000
	.word 0x00000700
	.word 0x00000700
	.word 0x00000700
	.word 0x00000700
	.word 0x00000700
	.word 0x00000700
	.word 0x00018009
	.word 0x00018009
	.word 0x00ac03f4
	.word 0x000000B2
	.word 0x00000030
	.word 0x00000030

