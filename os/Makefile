include Makefile.inc

SUBDIRS= main support memory screen

all:
	@for i in $(SUBDIRS); do\
	echo "Building $$i";\
	(cd $$i; $(MAKE) all); done
	(cd output; $(MAKE) all);
clean:
	@for i in $(SUBDIRS); do\
	echo "Cleaning $$i";\
	(cd $$i; $(MAKE) clean); done
	(cd output; $(MAKE) clean);
	rm kernel.bin
