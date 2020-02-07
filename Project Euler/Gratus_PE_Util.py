import fractions
import cmath
import itertools
from GPE_Geometry import *
import bisect
from math import factorial, sqrt
import math

# Input : Integer
# Output : Number of integer divisors.
def countDivisors(n):
	cnt = 0
	for i in range(1, (int(sqrt(n)) + 1)):
		if n % i == 0:
			if n / i == i:
				cnt = cnt + 1
			else:
				cnt = cnt + 2
	return cnt

# Input : Integer
# Output : List of all divisors, sorted
def allDivisors(n):
	divisors = []
	for i in range(1, (int(sqrt(n)) + 1)):
		if n % i == 0:
			if n / i == i:
				divisors += [i]
			else:
				divisors += [i,n//i]
	return sorted(divisors)

# Input : Integer
# Output : sum of function-applied digit of n
def sum_on_digit(n, function):
	ls = list(map(int,str(n)))
	s = 0
	for i in ls:
		s += function(i)
	return s

# Output : Is S a palindrome?
def check_palindrome(S):
	l = len(S)
	for i in range(l//2):
		if S[i] != S[l-i-1]:
			return False
	return True

# Input : Integer
# Output : Number of integer partitions of n
def Partitions(n):
	parts = [1]+[0]*n
	for t in range(1, n+1):
		for i, x in enumerate(range(t, n+1)):
			parts[x] += parts[i]
	return parts[n]

def Combination(n, m):
	return factorial(n)//(factorial(m)*factorial(n-m))

def Permutation(n,m):
	return factorial(n)//factorial(n-m)

#Returns all primes up to n
def sieve(n):
	prime = [True] * (n + 1)
	prime_list = []
	prime[0] = prime[1] = False
	prime_list.append(2)
	for i in range(3, n + 1, 2):
		if prime[i]: prime_list.append(i)
		for j in range(i * i, n + 1, i):
			prime[j] = False
	return prime_list

#Returns all prime factors of n. Sieve needed.
def primefactors(n, primes):
	ret = []
	for prime in primes:
		if n % prime == 0:
			ret.append(prime)
			n /= prime
	if n>1:
		ret.append(n)
	return ret

#Euler_Phi Function
def Euler_Phi(n, primes):
	pfactors = primefactors(n, primes)
	r = n
	for p in pfactors:
		r *= (1.0-1.0/p)
	return int(r)

#Schoolbook Algorithm for primality testing, with some optimizations.
def is_prime(n):
	if n == 2 or n == 3: return True
	if n < 2 or n % 2 == 0: return False
	if n < 9: return True
	if n % 3 == 0: return False
	r = int(n ** 0.5)
	f = 5
	while f <= r:
		if n % f == 0: return False
		if n % (f + 2) == 0: return False
		f += 6
	return True

#returns g,x,y such that ax+by = gcd(a,b)
def extended_GCD (a,b):
	if a == 0:
		return b, 0, 1
	else:
		g, x, y = extended_GCD(b % a, a)
		return g, y - (b // a) * x, x

#When x is in list a: returns first occurence
#When not : returns -1
def BinarySearch(x, a):
	i = bisect.bisect_left(a, x)
	if i != len(a) and a[i] == x:
		return i
	else:
		return -1

def primecount(n):
	return len(sieve(n))

def nonresidue(prime):
	for i in range(1,prime-1):
		if pow(i,(prime-1)//2,prime)!=1:
			return i

# Solve x^2 = n mod p in O(log^2 p) time.
def Tonelli_Shanks(n,p):
	if pow(n,(p-1)//2,p)!=1:
		return -1
	s = 0
	u = p-1
	while u%2==0:
		u //= 2
		s+=1
	q = u
	z = nonresidue(p)
	m = s
	c = pow(z,q,p)
	t = pow(n,q,p)
	r = pow(n,(q+1)//2,p)
	while True:
		if t==0:
			return 0
		if t==1:
			return r
		i = 1
		while pow(t,pow(2,i),p) != 1:
			i+=1
		b = pow(c,pow(2,m-i-1),p)
		m = i
		c = pow(b,2,p)
		t = (t*b*b)%p
		r = (r * b)%p

# Solve ax^2 + bx + c = k mod p
def modulo_quadratic_solve(a,b,c,k,p):
	u = Tonelli_Shanks((b*b-4*a*c+4*a*k)%p,p)
	if u == -1:
		return -1
	else:
		x1 = (u-b)%p
		x1 *= pow(2*a,p-2,p)
		x2 = (p-u-b)%p
		x2 *= pow(2 * a, p - 2, p)
		return x1, x2

def powerset(s):
	ls = []
	for n in range(0, len(s)+1):
		ls += [list(i) for i in itertools.combinations(s, n)]
	return ls


class Polynomial:
	def __init__(self, n):
		self.degree = n
		self.poly = [0]*(n+1)
	def print(self):
		print(self.poly)
	def identity(self):
		for i in range(0, self.degree+1):
			self.poly[i] = 0
		self.poly[0] = 1
	def evaluate(self, x):
		res = 0
		for i in range(0, self.degree+1):
			res = res + ((x**i) * (self.poly[i]))
		return res
	def multiplication(self,other):
		result = Polynomial(self.degree+other.degree)
		for i in range(0,self.degree+1):
			for j in range(0, other.degree+1):
				result.poly[i+j] = self.poly[i]*other.poly[j]
	def addition(self,other):
		result = Polynomial(max(self.degree,other.degree))
		for i in range(0, self.degree+1):
			result.poly[i] += self.poly[i]
			result.poly[i] += other.poly[i]
	def constantmulti(self,k):
		for i in range(0, self.degree+1):
			self.poly[i] *= k

def Lagrange_Interpolation(k,pts, ypts):
	result = Polynomial(k-1)
	basisset = [Polynomial(k-1)]*(k+1)
	for i in range(0,k+1):
		basisset[i].identity()
		for j in range(0,k+1):
			if j == i:
				continue
			else:
				newpoly = Polynomial(1)
				newpoly.poly[0] = (-pts[j])/(pts[i]-pts[j])
				newpoly.poly[1] = 1/(pts[i]-pts[j])
				basisset[i].multiplication(newpoly)
	for i in range(0,k+1):
		result.addition(basisset[i].constantmulti(ypts[i]))
	return result