include ../../Makefile.inc

all: gdt.o
	cp *.o $(OUTPUT)/

%.o: %.c
	$(CC) $(CFLAGS) -c $(.SOURCE)

clean:
	rm *.o
