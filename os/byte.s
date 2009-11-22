[BITS 32]

[GLOBAL outb]
[GLOBAL inb]
[GLOBAL inw]

outb:
push ebp
mov ebp, esp
mov edx, [ebp+8]


ret

inb:
push ebp
mov ebp, esp
mov edx, [ebp+8]
in eax, dx
pop ebp
ret

inw:
ret
