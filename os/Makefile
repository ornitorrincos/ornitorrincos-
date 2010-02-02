CC=i586-elf-gcc
LD=i586-elf-ld
CFLAGS=-O0 -Wall -Wextra -ansi -pedantic -nostdlib -nostartfiles -nodefaultlibs
OBJS=kernel.o vga.o kstr.o memory.o kmath.o

all: asm $(OBJS)
	$(LD) -T linker.ld -o kernel.bin loader.o kernel.o byte.o vga.o kstr.o cpu_model.o memory.o kmath.o

asm:
	nasm -f elf -o loader.o loader.s
	nasm -f elf -o byte.o byte.s
	nasm -f elf -o cpu_model.o cpu_model.s

%.o : %.c
	$(CC) -o $(.SOURCE) -c $(.SOURCE) $(CFLAGS)

clean:
	rm loader.o
	rm byte.o
	rm cpu_model.o
	rm $(OBJS)
	rm kernel.bin
