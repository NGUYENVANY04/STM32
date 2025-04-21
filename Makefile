CC          := arm-none-eabi-gcc
OBJCOPY     := arm-none-eabi-objcopy
MACH        := cortex-m3

CFLAGS      := -Ilib -mcpu=$(MACH) -mthumb -mfloat-abi=soft -Wall -O0
LDFLAGS     := -nostdlib -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs \
	       -T linker.ld -Wl,-Map=build/final.map

SRC_DIR     := src
LIB_DIR     := lib
DRV_DIR     := $(SRC_DIR)/drivers
STARTUP_DIR := Startup
BUILD_DIR   := build
SIZE        := arm-none-eabi-size
SRC_FILES := \
	$(STARTUP_DIR)/startup.c \
	$(SRC_DIR)/main.c \
	$(LIB_DIR)/rcc.c \
	$(LIB_DIR)/gpio.c \
	$(LIB_DIR)/adc.c \
	$(LIB_DIR)/uart.c \
	$(LIB_DIR)/syscall.c \
	$(DRV_DIR)/log_info.c \
	$(DRV_DIR)/temp.c

OBJS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

TARGET_ELF  := $(BUILD_DIR)/firmware.elf
TARGET_BIN  := $(BUILD_DIR)/firmware.bin


.PHONY: all clean flash

all: $(TARGET_BIN)
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(TARGET_ELF): $(OBJS) linker.ld
	$(CC) $(LDFLAGS) $(OBJS) -o $@
	$(SIZE) $@
$(TARGET_BIN): $(TARGET_ELF)
	$(OBJCOPY) -O binary $< $@

flash: $(TARGET_BIN)
	st-flash --reset write $(TARGET_BIN) 0x8000000

clean:
	rm -rf $(BUILD_DIR)

