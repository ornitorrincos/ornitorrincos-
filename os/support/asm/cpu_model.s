[GLOBAL cpu_model]
; 48 char long string

cpu_model:
    xchg bx, bx
    push ebp
    mov ebp, esp
    
    mov edi, [ebp+8]
    
    mov eax, 0x80000002
    cpuid
    
    mov [edi], eax
    mov [edi+4], ebx
    mov [edi+8], ecx
    mov [edi+12], edx
    
    mov eax, 0x80000003
    cpuid
    
    mov [edi+16], eax
    mov [edi+20], ebx
    mov [edi+24], ecx
    mov [edi+28], edx
    
    mov eax, 0x80000004
    cpuid
    
    mov [edi+32], eax
    mov [edi+36], ebx
    mov [edi+40], ecx
    mov [edi+44], edx
    
    pop ebp
    ret
