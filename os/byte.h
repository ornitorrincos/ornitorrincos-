#ifndef BYTE_H
#define BYTE_H

#include "datatypes.h"

void outb(u16int port, u8int value);
u8int inb(u16int port);
u16int inw(u16int port);

#endif
