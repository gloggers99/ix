#include "serial.h"
#include "io.h"

int serial_initialize() {
	outb(PORT + 1, 0x00);
	outb(PORT + 3, 0x80);
	outb(PORT + 0, 0x03);
	outb(PORT + 1, 0x00);
	outb(PORT + 3, 0x03);
	outb(PORT + 2, 0xC7);
	outb(PORT + 4, 0x0B);
	outb(PORT + 4, 0x1E);

	outb(PORT + 0, 0xAE);

	if (inb(PORT + 0) != 0xAE) {
		return 1;
	}

	outb(PORT + 4, 0x0f);

	return 0;
}

int serial_recieved() {
	return inb(PORT + 5) & 1;
}

char read_serial() {
	while (serial_recieved() == 0);

	return inb(PORT);
}

int serial_transmit_empty() {
	return inb(PORT + 5) & 0x20;
}

void serial_write(char data) {
	while (serial_transmit_empty() == 0);

	outb(PORT, data);
}
