#!/bin/sh

nasm -g -f elf64 cpuid.s
nasm -g -f elf64 simd.s
nasm -g -f elf64 amd_simd.s
nasm -g -f elf64 pae.s
nasm -g -f elf64 model.s

gcc -g -c cpu.c -o cpu.o
gcc -g cpuid.o simd.o amd_simd.o pae.o model.o cpu.o -o cpuid
