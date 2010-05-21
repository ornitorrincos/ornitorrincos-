#include "memory.h"

memory_t memaddr(struct multiboot_info *mbd)
{
    memory_t local;
    
    local.memory_low = (*mbd).mem_lower;
    local.memory_high = (*mbd).mem_upper;
    
    return local;
}

void  dump_memory(mptr *addr, u32int amount)
{
    u32int i;
    kprint("Memory dump address: ", COMPOSE(BB, FL));
    kphex((u32int) addr, COMPOSE(BB, FL));
    kprint("\n", COMPOSE(BB, FL));
    for(i=0;i<amount;i++)
    {
        kphex(*addr, COMPOSE(BB, FL));
        kprint(" ", COMPOSE(BB, FL));
        addr += 1;
    }
}

void kmemset(mptr *mem, u32int constant, u32int size)
{
    u32int i;
    for(i=0;i<size;i++)
    {
        *mem= constant;
        mem++;
    }
}
