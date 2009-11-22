all:
	nasm -f elf -o loader.o loader.s
	nasm -f elf -o byte.o byte.s
	i586-elf-gcc -o kernel.o -c kernel.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -masm=intel
	i586-elf-gcc -o kio.o -c kio.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -masm=intel
	i586-elf-ld -T linker.ld -o kernel.bin loader.o kernel.o kio.o byte.o
clean:
	rm loader.o
	rm kernel.o
	rm kio.o
	rm kernel.bin
