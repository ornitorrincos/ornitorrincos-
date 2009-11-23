[BITS 32]

[GLOBAL outb]
[GLOBAL inb]
[GLOBAL inw]

; xchg bx, bx
; manual bochs breakpoint

outb:
xchg bx, bx
push ebp
mov ebp, esp
mov edx, [ebp+8]
mov eax, [ebp+12]
out dx, al ; test with eax and al
ret

inb:
xchg bx, bx
push ebp
mov ebp, esp
mov edx, [ebp+8]
in eax, dx
pop ebp
ret

; should be almost the same as inb?
inw:
xchg bx, bx
push ebp
mov ebp, esp
mov edx, [ebp+8]
in eax, dx
pop ebp
ret
