[GLOBAL model]
;needs a 48 chars long string

model:
    mov rax, 0x80000002
    cpuid
    
    mov [rdi], rax
    mov [rdi+4], rbx
    mov [rdi+8], rcx
    mov [rdi+12], rdx
    
    mov rax, 0x80000003
    cpuid
    
    mov [rdi+16], rax
    mov [rdi+20], rbx
    mov [rdi+24], rcx
    mov [rdi+28], rdx
    
    mov rax, 0x80000004
    cpuid
    
    mov [rdi+32], rax
    mov [rdi+36], rbx
    mov [rdi+40], rcx
    mov [rdi+44], rdx
    ;mov [rdi+48], rax
    
    ret
