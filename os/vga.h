#ifndef VGA_H
#define VGA_H

#include "byte.h"

#define VIDEO 0xB8000

void kchar(const char c);
void kprint(const char *str);
void mv_cursor(u32int row, u32int col);
void clear_screen(void);

#endif
