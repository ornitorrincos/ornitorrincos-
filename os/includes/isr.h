#ifndef ISR_H
#define ISR_H
#include <datatypes.h>

struct registers
{
    u32int ds;
    
    // General registers
    u32int edi;
    u32int esi;
    u32int ebp;
    u32int esp;
    u32int ebx;
    u32int edx;
    u32int ecx;
    u32int eax;
    
    // interrupt
    u32int int_no;
    u32int err_no;
    
    // Other
    u32int eip;
    u32int cs;
    u32int eflags;
    u32int useresp;
    u32int ss;
};

void isr_handler(struct registers reg);
void unhandled_exception(struct registers reg);

#endif
