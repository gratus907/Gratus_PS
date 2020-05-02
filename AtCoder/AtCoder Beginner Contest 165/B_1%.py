from math import *
x = int(input())
a = 0
cur = 100
while cur < x:
	cur = int(cur * 1.01 + 10**-7)
	a+=1
print(a)
