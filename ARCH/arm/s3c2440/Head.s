mov SP #4096
bl AsmInitWatchDog
bl AsmInitInterrupt
bl AsminitSDRAM
bl main
loop: bl loop
