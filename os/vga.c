#include "vga.h"
#include "kstr.h"
#include "colors.h"

u32int grow = 0;
u32int gcol = 0;

/* prints a character to current cursor location */
void kpchar(const char c,const u8int color)
{
    u8int *videoram = (u8int*) VIDEO + 2*(grow*80 + gcol);
    
    *videoram = c;
    videoram++;
    *videoram = color;
    mv_cursor(gcol+1, grow);
}

void kpint(const u32int num,const u8int color)
{
    u32int aux, aux2, count, r;
    r = 0;
    aux = num;
    aux2 = num;
    do
    {
        count=kdigitlen(aux2);
        aux=kdigit(aux2);
        kpchar(0x30+aux, color);
        aux2 = aux2-(aux*10*count);
        if(count < 10)
        {
            r = 1;
        }
    }while(r != 1);
    
}

void kprint(const char *str, const u8int color)
{
    while(*str != '\0')
    {
        kpchar(*str, color);
        str++;
    }
}

void mv_cursor(u32int col, u32int row)
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
    
    u8int *videoram = (u8int*) VIDEO;
    
    for(i=0;i<80*24;i++)
    {
        *videoram=0x00;
        videoram++;
        *videoram = 0x00;
        videoram++;
    }
}
