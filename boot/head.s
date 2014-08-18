.global TH_START
.global SendByte
TH_START:
	b HandleReset
	.word HandleUndefine
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
	loop: bl loop
AsmInitWatchDog:
	ldr r3,=0x53000000
	ldr r4,=0
	str r4,[r3]
	mov PC,r14
AsmInitClock:
	mov PC,r14
AsmInitUart:
	ldr r2,=0x50000004
	ldr r3,=0x30;
	str r3,[r2]
	adr r1,BootLoaderMsg
0:	ldr r0,[r1,#1]!
	bl SendByte
	cmp r0,#0
	bne 0b
	mov PC,r14
AsminitSDRAM:
	mov PC,r14

HandleUndefine:
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
BootLoaderMsg:
	.ascii "Welcome to me,I am v-bios\r\n\0"
