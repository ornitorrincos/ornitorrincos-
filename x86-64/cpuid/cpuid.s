[GLOBAL VendorString]

VendorString:
    mov rax, 0
    cpuid
    
    mov [rdi], rbx
    mov [rdi+4], rdx
    mov [rdi+8], rcx
    mov byte [rdi+12], 0
    ;cpuid in order: rbx, rdx, rcx
    
    ret
