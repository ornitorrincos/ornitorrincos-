#include "vga.h"

u8int *videoram = (u8int*) 0xB8000;

u32int grow = 0;
u32int gcol = 0;

void kprint(const char *str)
{
    int i = 0;
    
    videoram = (u8int*) VIDEO + 2*((grow*80) + gcol);
    
    /*videoram starts on first character byte*/
    while(str[i] != '\0')
    {
        *videoram=str[i]; /*copy the letter to the videoram position*/
        videoram++; /*move pointer to color byte*/
        *videoram = 0x07; /*foreground and background colors*/
        videoram++; /*move pointer to next character byte*/
        i++; /*next character on string*/
    }
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
    for(i=0;i<80*25;i++)
    {
        *videoram=0x0;
        videoram++;
        *videoram = 0x00;
        videoram++;
    }
}
