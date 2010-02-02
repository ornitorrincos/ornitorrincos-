#ifndef MEMORY_H
#define MEMORY_H

#include "datatypes.h"
#include "multiboot.h"
#include "vga.h"
#include "colors.h"

typedef struct multiboot_memory_map
{
    u32int size;
    u32int base_addr_low;
    u32int base_addr_high;
    u32int length_low;
    u32int length_high;
    u32int type;
} multiboot_memory_map_t;

typedef struct memory
{
	u32int memory_low;
	u32int memory_high;
} memory_t;

memory_t memaddr(struct multiboot_info *mbd);

/* prints to screen the memory area that starts at addr and continues amount 
*  Take into account the it print two word(4 bytes) for each amount unit
*/
void dump_memory(u32int *addr, u32int amount);

#endif
