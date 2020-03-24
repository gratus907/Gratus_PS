list = input().split()

A = int(list[0])
B = int(list[1])
C = int(list[2])

print ((A+B)%C)
print ((A%C+B%C)%C)
print ((A * B)%C)
print ((A%C * B%C)%C)
