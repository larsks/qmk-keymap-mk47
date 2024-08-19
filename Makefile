QMK_FIRMWARE_DIR=$(shell git -C .. rev-parse --show-toplevel)
FIRMWARE=$(QMK_FIRMWARE_DIR)/inland_mk47_larsks.bin

$(FIRMWARE): rules.mk keymap.c config.h
	qmk compile

all: $(FIRMWARE)

flash: $(FIRMWARE)
	qmk flash

clean:
	rm -f $(FIRMWARE)
