all:
	nasm -f elf -o loader.o loader.s
	nasm -f elf -o byte.o byte.s
	nasm -f elf -o cpu_model.o cpu_model.s
	i586-elf-gcc -o kernel.o -c kernel.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -masm=intel
	i586-elf-gcc -o vga.o -c vga.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -masm=intel
	i586-elf-gcc -o kstr.o -c kstr.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -masm=intel
	i586-elf-gcc -o memory.o -c memory.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -masm=intel
	i586-elf-ld -T linker.ld -o kernel.bin loader.o kernel.o byte.o vga.o kstr.o cpu_model.o
clean:
	rm loader.o
	rm byte.o
	rm cpu_model.o
	rm kernel.o
	rm vga.o
	rm kstr.o
	rm kernel.bin
