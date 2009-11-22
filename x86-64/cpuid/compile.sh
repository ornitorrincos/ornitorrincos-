#!/bin/sh

nasm -f elf64 cpuid.s
nasm -f elf64 simd.s
nasm -f elf64 3dnow.s
nasm -f elf64 pae.s
nasm -f elf64 model.s
gcc -c cpu.c -o cpu.o
gcc cpuid.o simd.o 3dnow.o pae.o model.o cpu.o -o cpuid
