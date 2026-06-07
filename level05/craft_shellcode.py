from pwn import *
shellcode = asm(shellcraft.sh())

print(shellcode)
