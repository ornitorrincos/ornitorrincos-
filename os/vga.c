#include "vga.h"
#include "kstr.h"

u8int *videoram = (u8int*) 0xB8000;

u32int grow = 0;
u32int gcol = 0;

/* prints a character to current cursor location */
void kpchar(const char c)
{
    videoram = (u8int*) VIDEO + 2*((grow-80) + gcol);
    
    *videoram=c;
    videoram++;
    *videoram= 0x07;
}

void kpint(const u32int num)
{
    int aux, count;
    aux = num;
    count = 0;
    
    do
    {
        /* We get the current  number's length */
        while(aux>10)
        {
            aux = aux/10;
            count++;
        }
        kpchar((const char*) 0x0+kdigit(num));
        num = num-kdigit(num)*count;
        count--;
        
    } while(count > 0);
}

void kprint(const char *str)
{
    
}

void mv_cursor(u32int row, u32int col)
{
    u16int pos = (row*80) + col;
    
    grow = row;
    gcol = col;
    
    outb(0x3D4, 0x0F);
    outb(0x3D5, pos);
    
    outb(0x3D4, 0x0E);
    outb(0x3D5, pos>>8);
}

void clear_screen(void)
{
    int i;
    
    videoram = (u8int*) VIDEO;
    
    for(i=0;i<80*24;i++)
    {
        *videoram=0x00;
        videoram++;
        *videoram = 0x00;
        videoram++;
    }
}
