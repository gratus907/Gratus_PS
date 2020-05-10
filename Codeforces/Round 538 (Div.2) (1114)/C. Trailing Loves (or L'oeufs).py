import math

facts = []
fcounts = []

def primefactors(n):
	c = 0
	if n%2 == 0:
		while n%2==0:
			c+=1
			n = n//2
		facts.append(2)
		fcounts.append(c)
	for i in range(3, (int(math.sqrt(n)+1)),2):
		c = 0
		if n % i == 0:
			while n % i == 0:
				c += 1
				n = n // i
			facts.append(i)
			fcounts.append(c)
	if n>2:
		facts.append(n)
		fcounts.append(1)

def task(x, u):
	t = 0
	p = u
	while True:
		if x<p:
			return t
		else:
			t+=(x//p)
		p*=u

n, b = map(int, input().split())
primefactors(b)
l = len(facts)
val = int(1e18)
#print(facts)
#print(fcounts)
for i in range(l):
	x = facts[i]
	a = task(n,x)
	#print(a, "for value:", x)
	val = min(val, a//fcounts[i])
if val is int(1e18):
	print("0")
else:
	print(int(val))
