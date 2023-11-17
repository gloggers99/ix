#include "vga.h"
#include "serial.h"
#include "io.h"

int kmain() {
	vga_initialize();

	vga_puts("ix kernel\n");
	vga_puts("starting serial...\n");

	if (serial_initialize() != 0) {
		vga_puts("serial failed to start!!!\n");
	}

	vga_puts("serial started.\n");

	for (;;) {}

	return 0;
}
