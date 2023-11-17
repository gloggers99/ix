#include "vga.h"

int kmain() {
	vga_initialize();

	vga_puts("ix kernel");

	for (;;) {}

	return 0;
}
