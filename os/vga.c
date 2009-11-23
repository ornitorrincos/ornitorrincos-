#include "vga.h"

void mv_cursor(u32int row, u32int col)
{
    u16int pos = (row*80) + col;
    
    outb(0x3D4, 0x0F);
    outb(0x3D5, pos);
    
    outb(0x3D4, 0x0E);
    outb(0x3D5, pos>>8);
}
