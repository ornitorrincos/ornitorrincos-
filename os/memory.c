#include "memory.h"

memory_t memaddr(struct multiboot_info *mbd)
{
    memory_t local;
    
    local.memory_low = (*mbd).mem_lower;
    local.memory_high = (*mbd).mem_upper;
    
    return local;
}

void  dump_memory(u32int *addr, u32int amount)
{
    u32int i;
    kprint("Memory dump address: ", COMPOSE(BB, FL));
    kphex(addr, COMPOSE(BB, FL));
    kprint("\n", COMPOSE(BB, FL));
    for(i=0;i<amount;i++)
    {
        kphex(*addr, COMPOSE(BB, FL));
        kprint(" ", COMPOSE(BB, FL));
        addr += 1;
    }
}
