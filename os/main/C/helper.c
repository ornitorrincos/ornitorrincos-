#include <main.h>

void startup(void* mbd)
{
    char cpu[48];
    memory_t mem;
    char *boot_loader_name;
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
    dump_memory((mptr*) 0xB8000, 40);
}
