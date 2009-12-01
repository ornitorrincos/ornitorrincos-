#include "memory.h"

u32int memsize(struct multiboot_info *mbd)
{
    multiboot_memory_map_t* mmap = (multiboot_memory_map_t*) (mbd->mmap_addr);
    
    while(mmap < (mbd->mmap_addr + mbd->mmap_length))
    {
        mmap = (multiboot_memory_map_t*) ((u32int*)mmap + mmap->size + sizeof(u32int));
    }
    
    return (*mmap).size;
}
