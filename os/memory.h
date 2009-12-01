#ifndef MEMORY_H
#define MEMORY_H

#include "datatypes.h"
#include "multiboot.h"

typedef struct multiboot_memory_map
{
    u32int size;
    u32int base_addr_low;
    u32int base_addr_high;
    u32int length_low;
    u32int length_high;
    u32int type;
} multiboot_memory_map_t;

u32int memsize(struct multiboot_info *mbd);

#endif
