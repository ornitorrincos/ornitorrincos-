#include "memory.h"

memory_t memaddr(struct multiboot_info *mbd)
{
    memory_t local;
    
    local.memory_low = (*mbd).mem_lower;
    local.memory_high = (*mbd).mem_upper;
    
    return local;
}
