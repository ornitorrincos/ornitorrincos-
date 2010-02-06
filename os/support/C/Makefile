include ../../Makefile.inc

all: kmath.o kstr.o
	cp *.o $(OUTPUT)/

%.o: %.c
	$(CC) $(CFLAGS) -c $(.SOURCE)

clean:
	rm *.o
