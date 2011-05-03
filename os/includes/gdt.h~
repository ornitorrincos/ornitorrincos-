#include "datatypes.h"

struct gdt_entry
{
    u16int limit_low;
    u16int base_low;
    u8int base_middle;
    u8int access;
    u8int granularity;
    u8int base_high;
} __attribute__((packed));

struct gdt_ptr
{
    u16int limit;
    u32int base;
} __attribute__((packed));

void gdt_flush();

void gdt_set_gate(s32int num, u64int base, u64int limit, u8int access, u8int gran);
void gdt_install();
