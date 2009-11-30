CC=i586-elf-gcc
LD=i586-elf-ld
CFLAGS=-Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs

all:
	nasm -f elf -o loader.o loader.s
	nasm -f elf -o byte.o byte.s
	nasm -f elf -o cpu_model.o cpu_model.s
	$(CC) -o kernel.o -c kernel.c $(CFLAGS)
	$(CC) -o vga.o -c vga.c $(CFLAGS)
	$(CC) -o kstr.o -c kstr.c $(CFLAGS)
	$(CC) -o memory.o -c memory.c $(CFLAGS)
	$(CC) -o kmath.o -c kmath.c $(CFLAGS)
	$(LD) -T linker.ld -o kernel.bin loader.o kernel.o byte.o vga.o kstr.o cpu_model.o memory.o kmath.o
clean:
	rm loader.o
	rm byte.o
	rm cpu_model.o
	rm kernel.o
	rm vga.o
	rm kstr.o
	rm kernel.bin
