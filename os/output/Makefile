include ../Makefile.inc

OBJS=byte.o cpu_model.o kmath.o kstr.o memory.o vga.o loader.o kernel.o

all:
	$(LD) -T ../linker.ld $(OBJS) -o ../kernel.bin
clean:
	rm $(OBJS)
