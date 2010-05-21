#ifndef BYTE_H
#define BYTE_H

#include "datatypes.h"

void outb(u32int port, u32int value);
u8int inb(u32int port);
u16int inw(u32int port);

#endif
