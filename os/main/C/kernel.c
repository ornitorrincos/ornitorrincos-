#include "vga.h"
#include "cpuid.h"
#include "memory.h"
#include "colors.h"
#include "kstr.h"
#include "gdt.h"

void kmain( void* mbd, unsigned int magic )
{
    char cpu[48];
    memory_t mem;
    char *boot_loader_name;
    if ( magic != 0x2BADB002 )
    {
        kprint("Error booting the kernel", COMPOSE(BB, BL));
    }
    
    gdt_install();
  
    boot_loader_name =(char*) ((long*)mbd)[16];  
    cpu_model(cpu);
    mem = memaddr((struct multiboot_info*) mbd);
    
    clear_screen();
    kprint(boot_loader_name, COMPOSE(BU, LFL));
    kprint("\n", COMPOSE (BU, LFL));
    kprint(cpu, COMPOSE(BU, LFL));
    kprint("\n", COMPOSE(BU, LFL));
    kprint("LOWER MEMORY ", COMPOSE(BU, LFL));
    kpint(mem.memory_low, COMPOSE(BU, LFL));
    kprint("\n", COMPOSE(BU, LFL));
    kprint("UPPER MEMORY ", COMPOSE(BU, LFL));
    kpint(mem.memory_high, COMPOSE(BU, LFL));
    kprint("\n", COMPOSE(BB, FL));
    /*dump_memory((u32int*) 0x100000, 5);*/
    dump_memory((u32int*) 0xB8000, 5);
}
