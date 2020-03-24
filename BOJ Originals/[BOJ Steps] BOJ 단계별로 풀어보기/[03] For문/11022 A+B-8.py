n = int(input())
a = 0
mem = []
while a < n :
      mem.append(input().split())
      a = a+1

a = 0
t = 0
while a < n :
     t = int(mem[a][0])+int(mem[a][1])

     print ('Case #'+str(a+1)+': '+str(mem[a][0]) + ' + ' + str(mem[a][1]) + ' = ' +str(t))
     a =a+1