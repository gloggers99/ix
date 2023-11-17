nasm -felf boot.asm  -o boot.o
i686-elf-gcc -c ./kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c ./vga.c -o vga.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c ./io.c -o io.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c ./serial.c -o serial.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -T  linker.ld -o ix.bin -ffreestanding -O2 -nostdlib boot.o io.o kernel.o vga.o serial.o -lgcc
