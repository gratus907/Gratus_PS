n = float(input())

mem = input().split()
k = len(mem)

for i in range (0,k) :
    mem[i] = int(mem[i])

t = 0

for i in range (0,k) :
    t = (t + mem [i])

M = sorted(mem)[k-1]

for i in range (0,k) :
    mem[i] = (mem[i]/M)*100

t = 0
for i in range (0,k) :
    t = (t + mem [i])

print (t/k)