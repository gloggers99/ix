#ifndef SERIAL_H
#define SERIAL_H

#define PORT 0x3F8

int serial_initialize();

int serial_recieved();

char serial_read();

int serial_transmit_empty();

void serial_write(char data);

#endif
