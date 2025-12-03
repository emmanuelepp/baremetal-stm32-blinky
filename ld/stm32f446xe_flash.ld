/* stm32f446xe_flash.ld - minimal linker script for NUCLEO-F446RE */

ENTRY(Reset_Handler)

/* --- Memory layout --- */
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
    RAM   (xrw) : ORIGIN = 0x20000000, LENGTH = 128K
}

/* Top of stack */
_estack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
    /* Vector table at start of flash */
    .isr_vector :
    {
        KEEP(*(.isr_vector))
    } > FLASH

    /* Code + const */
    .text :
    {
        *(.text*)       /* all .text and .text.* */
        *(.rodata*)     /* const data */
        *(.glue_7) *(.glue_7t)
        *(.eh_frame*)
    } > FLASH

    /* Initialized data: load from FLASH, run in RAM */
    .data : AT (ADDR(.text) + SIZEOF(.text))
    {
        _sdata = .;
        *(.data*)
        _edata = .;
    } > RAM

    _sidata = LOADADDR(.data);

    /* Zero-initialized data */
    .bss :
    {
        _sbss = .;
        *(.bss*)
        *(COMMON)
        _ebss = .;
    } > RAM

    /* Simple heap/stack placeholder (no pasa nada si no lo usas) */
    ._user_heap_stack :
    {
        . = . + 0x400; /* 1 KB */
        _end = .;
    } > RAM
}
