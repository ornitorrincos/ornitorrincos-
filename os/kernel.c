#include "vga.h"
#include "cpuid.h"
#include "memory.h"
#include "colors.h"
#include "kstr.h"

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
    kprint(cpu, COMPOSE(BU, LFL));
    mv_cursor(0, 2);
    kprint("MEMORY AVAIBLE   ", COMPOSE(BU, LFL));
    mv_cursor(kstrlen("MEMORY AVAIBLE   "), 2);
    kpint(mem, COMPOSE(BU, LFL));
    mv_cursor(0, 3);
    kprint(boot_loader_name, COMPOSE(BB, FL));
    mv_cursor(0, 4);
    kprint("ornitorrincos calculator", COMPOSE(BB, FL));
    mv_cursor(kstrlen("ornitorrincos calculator")+4, 4);
    kprint("VERSION", COMPOSE(BB, FL));
    mv_cursor(kstrlen("ornitorrincos calculator")+kstrlen("VERSION")+5, 4);
    kpint(1, COMPOSE(BB, FL));
}
