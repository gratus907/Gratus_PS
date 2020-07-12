import time
from lib import Gratus_PE_Util as GPE
from math import *
import itertools


def main():
	ub = 50000000
	P = set()
	primes2 = GPE.sieve(int(pow(ub,1/2))+1)
	primes3 = GPE.sieve(int(pow(ub,1/3))+1)
	primes4 = GPE.sieve(int(pow(ub,1/4))+1)
	c = 0
	for (i,j,k) in itertools.product(primes2,primes3,primes4):
		c+=1
		x = i**2+j**3+k**4
		if x > ub:
			continue
		else:
			P.add(x)
	print(len(P))


if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
