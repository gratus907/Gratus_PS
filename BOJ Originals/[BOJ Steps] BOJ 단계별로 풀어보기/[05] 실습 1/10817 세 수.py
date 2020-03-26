mem = input().split()
a = 0
b = 1

for i in range (0,3) :
    mem[i] = int(mem[i])

smem = sorted(mem)

print (smem[1])
