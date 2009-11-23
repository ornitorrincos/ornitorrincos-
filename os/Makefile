all:
	nasm -f elf -o loader.o loader.s
	nasm -f elf -o byte.o byte.s
	i586-elf-gcc -o kernel.o -c kernel.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -masm=intel
	i586-elf-gcc -o vga.o -c vga.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -masm=intel
	i586-elf-gcc -o kstr.o -c kstr.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -masm=intel
	i586-elf-ld -T linker.ld -o kernel.bin loader.o kernel.o byte.o vga.o kstr.o
clean:
	rm loader.o
	rm kernel.o
	rm vga.o
	rm kstr.o
	rm kernel.bin
