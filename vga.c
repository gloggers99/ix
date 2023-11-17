#include "vga.h"

#include <stddef.h>
#include <stdint.h>

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t vga_column,
       vga_row;

uint8_t vga_color;

uint16_t *vga_buffer;

size_t strlen(const char* str) 
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

void vga_clear() {
	for (size_t i = 0; i < VGA_HEIGHT; i++) {
		for (size_t j = 0; j < VGA_WIDTH; j++) {
			const size_t index = i * VGA_WIDTH + j;
			vga_buffer[index] = vga_entry(' ', vga_color);
		}
	} 
}

void vga_initialize() {
	vga_column = 0;
	vga_row    = 0;

	vga_color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);

	vga_buffer = (uint16_t*) 0xB8000;

	vga_clear();
}

void vga_putc_at(const char ch, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	vga_buffer[index] = vga_entry(ch, vga_color);
}

void vga_putc(const char ch) {
	vga_putc_at(ch, vga_column, vga_row);

	if (++vga_column == VGA_WIDTH) {
		vga_column = 0;
		if (++vga_row == VGA_HEIGHT) {
			vga_row = 0;
		}
	}

}

void vga_puts(const char *str) {
	for (size_t i = 0; i < strlen(str); i++) {
		vga_putc(str[i]);
	}
}
