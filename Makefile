QMK_FIRMWARE_DIR=$(shell git -C .. rev-parse --show-toplevel)
FIRMWARE=$(QMK_FIRMWARE_DIR)/inland_mk47_larsks.bin

all: $(FIRMWARE)

$(FIRMWARE): rules.mk keymap.c config.h
	qmk compile -kb inland/mk47 -km larsks

flash: $(FIRMWARE)
	qmk flash

clean:
	rm -f $(FIRMWARE)
