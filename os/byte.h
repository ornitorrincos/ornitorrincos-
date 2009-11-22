#ifndef BYTE_H
#define BYTE_H

#include "datatypes.h"

extern void outb(u16int port, u8int value);
extern u8int inb(u16int port);
extern u16int inw(u16int port);

#endif
