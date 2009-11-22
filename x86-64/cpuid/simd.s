[GLOBAL simd]

simd:
    ;rdi has the direction for the array [MMX, SSE, SSE2, SSE3, SSE4]
    mov rax, 1
    cpuid
    
    jmp mmx
mmx:
    mov rax, rdx
    and rax, 0x00800000
    cmp rax, 0x00800000
    je ok_mmx
    jne fail_mmx
ok_mmx:
    mov byte [rdi], 0x1
    jmp sse
fail_mmx:
    mov byte [rdi], 0x0
    jmp fail_sse

sse:
    mov rax, rdx
    and rax, 0x02000000
    cmp rax, 0x02000000
    je ok_sse
    jne fail_sse
ok_sse:
    mov byte [rdi+4], 0x1
    jmp sse2
fail_sse:
    mov byte [rdi+4], 0
    jmp fail_sse2

sse2:
    mov rax, rdx
    and rax, 0x04000000
    cmp rax, 0x04000000
    je ok_sse2
    jne fail_sse2
ok_sse2:
    mov byte [rdi+8], 0x1
    jmp sse3
fail_sse2:
    mov byte [rdi+8], 0x0
    jmp fail_sse3

sse3:
    mov rax, rcx
    and rax, 0x00000001
    cmp rax, 0x00000001
    je ok_sse3
    jne fail_sse3
ok_sse3:
    mov byte [rdi+12], 1
    jmp sse4
fail_sse3:
    mov byte [rdi+12], 0
    jmp fail_sse4

sse4:
    mov rax, rcx
    and rax, 0x00080000
    cmp rax, 0x00080000
    je ok_sse4
    jne fail_sse4
ok_sse4:
    mov byte [rdi+16], 1
    jmp exit
fail_sse4:
    mov byte [rdi+16], 0
    jmp exit

exit:
    ret

