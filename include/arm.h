#if 0
#pragma once

#define ARM_MODE_USR  0x10
#define ARM_MODE_FIQ  0x11
#define ARM_MODE_IRQ  0x12
#define ARM_MODE_SVC  0x13
#define ARM_MODE_ABT  0x17
#define ARM_MODE_UND  0x1b
#define ARM_MODE_SYS  0x1f

#define ARM_THUMB     (1 << 5)

#define ARM_FIQ_MASK  (1 << 6)
#define ARM_IRQ_MASK  (1 << 7)
#define ARM_INT_MASK  (ARM_IRQ_MASK | ARM_FIQ_MASK)

#define IrqEnable() \
    do \
    { \
        ULONG ulCpsr; \
        asm __VOLATILE__ ("mrs %0, cpsr\n" \
            "bic %0, %0, %1\n" \
            "msr cpsr_c, %0\n" \
            : "=r" (ulCpsr) \
            : "i" (ARM_IRQ_MASK) \
            : "memory"); \
    } while (0)

    
#define IrqDisable() \
    do \
    { \
        ULONG ulCpsr; \
        asm __VOLATILE__ ("mrs %0, cpsr\n" \
            "orr %0, %0, %1\n" \
            "msr cpsr_c, %0\n" \
            : "=r" (ulCpsr) \
            : "i" (ARM_IRQ_MASK) \
            : "memory"); \
    } while (0)

    
#define LockIrqPsr(ulCpsr) \
    do \
    {   \
        UINT32 tmp; \
        asm __VOLATILE__ ("mrs %0, cpsr\n" \
            "orr %1, %0, %2\n" \
            "msr cpsr_c, %1\n" \
            : "=r" (ulCpsr), "=r"(tmp) \
            : "i" (ARM_IRQ_MASK) \
            : "memory"); \
    } while (0)


#define UnlockIrqPsr(ulCpsr) \
    do \
    { \
        asm __VOLATILE__ ("msr cpsr_c, %0\n" \
            : \
            : "r" (ulCpsr) \
            : "memory"); \
    } while (0)


#define FiqEnable() \
    do \
    { \
        ULONG ulCpsr; \
        asm __VOLATILE__ ("mrs %0, cpsr\n" \
            "bic %0, %0, %1\n" \
            "msr cpsr_c, %0\n" \
            : "=r" (ulCpsr) \
            : "i" (ARM_FIQ_MASK) \
            : "memory"); \
    } while (0)
#endif
