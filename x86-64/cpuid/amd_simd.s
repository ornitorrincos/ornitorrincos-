[GLOBAL amd_simd]

amd_simd:
    mov rax, 0x80000001 ; rdi for the two elements array [3DNOW!, 3DNOW!+]
    cpuid
    
    sbb rax, rax
    sbb rbx, rbx
    mov rax, rdx
    and rax, 0x80000000
    mov rbx, 0x80000000
    neg rax ; negated so we don't go out-bounds
    neg rbx
    
    cmp rax, rbx
    
    je write_3dnow
    jne fail_3dnow
    
write_3dnow:
    mov byte [rdi], 0x1
    jmp Now_Ext
fail_3dnow:
    mov byte [rdi], 0
    jmp fail_3dnow_ext
Now_Ext:
    mov rax, 0x80000001
    cpuid
    
    sbb rax, rax
    sbb rbx, rbx
    mov rax, rdx
    and rax, 0x40000000
    mov rbx, 0x40000000
    neg rax
    neg rbx
    cmp rax, rbx
    
    je write_3dnow_ext
    jne fail_3dnow_ext
write_3dnow_ext:
    mov byte [rdi+4], 0x1
    jmp mmx_ext
fail_3dnow_ext:
    mov byte [rdi+4], 0x0
    jmp mmx_ext
mmx_ext:
    mov rax, 0x80000001
    cpuid
    
    sbb rax, rax
    sbb rbx, rbx
    mov rax, rdx
    and rax, 0x00400000
    mov rbx, 0x00400000
    cmp rax, rbx
    
    je write_mmx_ext
    jne fail_mmx_ext
write_mmx_ext:
    mov byte [rdi+8], 0x1
    jmp exit
fail_mmx_ext:
    mov byte [rdi+8], 0x0
    jmp exit
exit:
    ret
