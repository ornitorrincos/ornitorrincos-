[GLOBAL pae]

pae:
    mov rax, 0x1
    cpuid
    
    mov rbx, 0x00000040
    mov rax, rdx
    and rax, rbx
    cmp rax, rbx
    
    je write_pae
    jne fail_pae
write_pae:
    mov byte [rdi], 0x1
    jmp exit
fail_pae:
    mov byte [rdi], 0x0
    jmp exit
exit:
    ret
