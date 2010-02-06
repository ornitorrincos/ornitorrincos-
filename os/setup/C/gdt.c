#include <gdt.h>

struct gdt_entry gdt[3];
struct gdt_ptr gp;

void gdt_set_gate(s32int num, u64int base, u64int limit, u8int access, u8int gran)
{
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;
    
    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = ((limit >> 16) & 0x0F);
    
    gdt[num].granularity |= (gran & 0xF0);
    gdt[num].access = access;
}

void gdt_install()
{
    gp.limit = (sizeof(struct gdt_entry) * 3) -1;
    gp.base = (u32int) &gdt;
    
    gdt_set_gate(0,0,0,0,0);
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
    
    gdt_flush();
}
