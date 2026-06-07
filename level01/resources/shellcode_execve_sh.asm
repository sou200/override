
section .text
    global _start

_start:
    push dword 0x0068732f
    push dword 0x6e69622f
    mov eax, dword 11
    mov ebx, esp
    xor ecx, ecx
    xor edx, edx
    int 0x80