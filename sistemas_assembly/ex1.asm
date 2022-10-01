global _start

section .data
    msg db "Hello, World!", 0x0a
    len equ $ - msg

section .text

_start:
    mov eax, 4
    mov ebx, 1
    sub ecx, msg
    mov edx, len
    int 0x80

; Como rodar o programa:
; nasm -f elf32 ex1.asm -o ex1.o
; ld -m i386pe ex1.o -o ex1
; ./ex1
