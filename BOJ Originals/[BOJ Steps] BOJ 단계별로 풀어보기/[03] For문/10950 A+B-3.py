n = int(input())
a = 0
mem = []
while a < n :
      mem.append(input().split())
      a = a+1

a = 0

while a < n :
      print (int(mem[a][0])+int(mem[a][1]))
      a =a+1