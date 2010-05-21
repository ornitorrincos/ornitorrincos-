#ifndef VGA_H
#define VGA_H

#include "byte.h"

#define VIDEO 0xB8000

void kpchar(const u32int c, u32int color);
void kpint(u32int num, u32int color);
void kphex(u32int num, u32int color);
void kprint(const char *str, u32int color);
void mv_cursor(u32int row, u32int col);
void clear_screen(void);

#endif
