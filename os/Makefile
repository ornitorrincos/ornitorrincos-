PATH_CUSTOM=/usr/local/cross/install/bin/
BASEPATH=/home/ilcra1989/dev/misc/os
INC=$(BASEPATH)/includes
OUTPUT=$(BASEPATH)/output
CC_EXEC=i586-elf-gcc
LD_EXEC=i586-elf-ld
CC=$(PATH_CUSTOM)$(CC_EXEC)
LD=$(PATH_CUSTOM)$(LD_EXEC)
CFLAGS := -O0 -I$(INC) -Wall -Wextra -std=c99 -pedantic -nostdlib -nostartfiles -nodefaultlibs \
          -Wshadow -Wpointer-arith -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations -Wcast-align \
          -Wredundant-decls -Wnested-externs -Winline -Wstrict-prototypes -Wno-long-long
# -Wconversion
LINKER=$(BASEPATH)/linker.ld
AS=nasm -w-orphan-labels -f elf

PROJDIRS := main memory screen setup support

CFILES := $(shell find $(PROJDIRS) -mindepth 1 -maxdepth 3 -name "*.c")
ASFILES := $(shell find $(PROJDIRS) -mindepth 1 -maxdepth 3 -name "*.s")

OBJFILES := $(patsubst %.c,%.o,$(CFILES))
SOBJFILES := $(patsubst %.s,%.os,$(ASFILES))
OUTFILES := $(shell find $(OUTPUT) -mindepth 1 -maxdepth 3 -name "*.o*")

all: $(OBJFILES) $(SOBJFILES)
	@$(LD) -T $(LINKER) $(OUTFILES) -o $(BASEPATH)/kernel.bin
	
%.o: %.c
	@$(CC) -I$(INC) $(CFLAGS) -c $^ -o $(OUTPUT)/$(shell basename $@)

%.os: %.s
	@$(AS) $^ -o $(OUTPUT)/$(shell basename $@)
