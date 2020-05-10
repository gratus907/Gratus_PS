from math import sqrt
def is_prime(n):
	u = int(sqrt(n)+1)
	for i in range(2,u):
		if n%i == 0:
			return 0
	return 1

num = int(input())
a = 11
b = 0
while b<num:
	if is_prime(a):
		print(a, end = ' ')
		b+=1
	a += 10
