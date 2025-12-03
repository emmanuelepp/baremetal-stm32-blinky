# Toolchain
CC = arm-none-eabi-gcc
AS = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

# Project Name
PROJECT = STM32_BLINKY
TARGET_ELF = build/$(PROJECT).elf

# Flags
MCU = -mcpu=cortex-m4 -mthumb
CFLAGS = $(MCU) -Wall -g3 -O0 -ffreestanding -Iinclude -DSTM32F446xx
LDFLAGS  = $(MCU) -Tld/stm32f446xe_flash.ld -nostartfiles -Wl,--gc-sections -Wl,-Map=build/$(PROJECT).map

# Objects
OBJS = build/main.o build/init.o build/startup_stm32f446xx.o

# Rules
all: $(TARGET_ELF)

build:
	mkdir -p build

build/main.o: src/main.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build/init.o: src/init.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build/startup_stm32f446xx.o: src/startup/startup_stm32f446xx.s | build
	$(AS) $(MCU) -c $< -o $@

$(TARGET_ELF): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

bin: $(TARGET_ELF)
	$(OBJCOPY) -O binary $(TARGET_ELF) build/$(PROJECT).bin

clean:
	rm -rf build
