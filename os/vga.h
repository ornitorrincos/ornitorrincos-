#ifndef VGA_H
#define VGA_H

#include "byte.h"

#define VIDEO 0xB8000

void kpchar(const char c, u8int color);
void kpint(u32int num, u8int color);
void kphex(u32int num, u8int color);
void kprint(const char *str, u8int color);
void mv_cursor(u32int row, u32int col);
void clear_screen(void);

#endif
