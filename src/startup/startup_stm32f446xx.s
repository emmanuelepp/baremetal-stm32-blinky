    .syntax unified
    .cpu cortex-m4
    .fpu softvfp
    .thumb

    .global g_pfnVectors
    .global Reset_Handler

    .extern SystemInit
    .extern main

/* ---- Vector table ---- */
    .section .isr_vector,"a",%progbits
g_pfnVectors:
    .word _estack          /* initial stack pointer */
    .word Reset_Handler    /* reset handler */
    .word NMI_Handler
    .word HardFault_Handler
    .word Default_Handler  /* MemManage */
    .word Default_Handler  /* BusFault */
    .word Default_Handler  /* UsageFault */
    .word 0
    .word 0
    .word 0
    .word 0
    .word Default_Handler  /* SVC */
    .word Default_Handler  /* DebugMon */
    .word 0                /* reserved */
    .word Default_Handler  /* PendSV */
    .word Default_Handler  /* SysTick */

    /* more IRQs can be added later */

/* ---- Reset handler ---- */
    .section .text.Reset_Handler,"ax",%progbits
    .thumb_func
Reset_Handler:
    /* copy .data from flash to RAM */
    ldr r0, =_sidata
    ldr r1, =_sdata
    ldr r2, =_edata
1:
    cmp r1, r2
    bcs 2f               /* if r1 >= r2, done */
    ldr r3, [r0], #4
    str r3, [r1], #4
    b   1b
2:
    /* clear .bss section */
    ldr r0, =_sbss
    ldr r1, =_ebss
3:
    cmp r0, r1
    bcs 4f               /* if r0 >= r1, done */
    movs r2, #0
    str  r2, [r0], #4
    b   3b
4:
    /* call SystemInit and then main */
    bl SystemInit
    bl main

5:  /* if main returns, stay here */
    b 5b

/* ---- default handlers ---- */
    .thumb_func
NMI_Handler:
    b NMI_Handler

    .thumb_func
HardFault_Handler:
    b HardFault_Handler

    .thumb_func
Default_Handler:
    b Default_Handler