[BITS 32]

[GLOBAL outb]
[GLOBAL inb]
[GLOBAL inw]

outb:
push ebp
mov ebp, esp
mov edx, [ebp+8]
mov eax, [ebp+10] ; 2 bytes for short
out dx, eax
ret

inb:
push ebp
mov ebp, esp
mov edx, [ebp+8]
in eax, dx
pop ebp
ret

; should be almost the same as inb?
inw:
push ebp
mov ebp, esp
mov edx, [ebp+8]
in eax, dx
pop ebp
ret
