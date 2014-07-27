ldr SP,=4096
bl AsmInitWatchDog
bl AsmInitInterrupt
bl AsminitSDRAM
bl main
loop: bl loop
AsmInitWatchDog:
mov PC,r14
AsmInitInterrupt:
mov PC,r14
AsminitSDRAM:
mov PC,r14
