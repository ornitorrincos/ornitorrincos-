section .text:
global _start

_start:
    mov rax, 1
    cpuid
    and rdx, 0x00080000
    
    mov rax, 60
    mov rdi, 0
    syscall
