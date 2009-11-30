#include "vga.h"
#include "cpuid.h"
#include "memory.h"
#include "colors.h"

void kmain( void* mbd, unsigned int magic )
{
    char cpu[48];
    u32int mem;
    
    if ( magic != 0x2BADB002 )
    {
        kprint("Error booting the kernel", COMPOSE(BB, BL));
    }
  
    char * boot_loader_name =(char*) ((long*)mbd)[16];
    
    /* Kernel starts here */
    
    cpu_model(cpu);
    mem = memsize((struct multiboot_info*) mbd);
    
    mv_cursor(0, 1);
    /*kpint(9567);*/
    kprint(cpu, COMPOSE(BU, LFL));
    mv_cursor(0, 2);
    kprint(boot_loader_name, COMPOSE(BB, FL));
    mv_cursor(0, 3);
    kprint("ornitorrincos calculator", COMPOSE(BB, FL));
}
