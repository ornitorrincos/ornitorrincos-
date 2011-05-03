#ifndef MAIN_H
#define MAIN_H

#include "vga.h"
#include "cpuid.h"
#include "memory.h"
#include "colors.h"
#include "kstr.h"
#include "gdt.h"

void kmain(void *mbd, u32int magic);
void startup(void *mbd);

#endif
