#include "vga.h"
#include "kstr.h"
#include "kmath.h"
#include "colors.h"

/* cursor location global variables */
u32int grow = 0;
u32int gcol = 0;

/* Prints a character to current cursor location */
void kpchar(const char c,const u8int color)
{
    u8int *videoram = (u8int*) VIDEO + 2*(grow*80 + gcol);
    
    if(c == '\n')
    {
		mv_cursor(0, grow+1);
	} else if(c == '\t')
	{
		mv_cursor(gcol+8, grow);
	} else
	{
    *videoram = c;
    videoram++;
    *videoram = color;
    mv_cursor(gcol+1, grow);
	}
}

/* Prints an integer to current cursor location */
void kpint(u32int num,const u8int color)
{
    u32int len, digit;
    do
    {
    len = kdigitlen(num);
    digit = kdigit(num);
    /* Convert decimal digit to ascii code 4 -> 0x34 */
    kpchar(0x30+digit, color);
    num = num-(digit*power(10, len-1));
    } while(len > 1);
}

/* Prints a string to current cursor location */
void kprint(const char *str, const u8int color)
{
    while(*str != '\0')
    {
        kpchar(*str, color);
        str++;
    }
}

/* Moves the current cursor location */
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

/* Cleans the screen */
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
