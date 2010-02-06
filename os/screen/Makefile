include ../Makefile.inc

all: vga.o
	cp *.o $(OUTPUT)/

%.o: %.c
	$(CC) $(CFLAGS) -c $(.SOURCE)

clean:
	rm *.o
