# baremetal-stm32-blinky

LED blink example for the STM32F446RE (NUCLEO-F446RE board).

The project uses simple register-level code, a custom startup file and a linker script.

## Board

- MCU: **STM32F446RE**
- Board: **NUCLEO-F446RE**
- LED: **User LED on PA5**

## Project structure

```text
baremetal-stm32-blinky/
├── Makefile
├── ld/
│   └── stm32f446xe_flash.ld
├── src/
│   ├── main.c
│   ├── init.c
│   └── startup/
│       └── startup_stm32f446xx.s
└── include/
    └── stm32f4xx.h
