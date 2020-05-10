import time
import Gratus_PE_Util as GPE
from math import *

def main():
	candidate = GPE.sieve(10**3)
	curbest = 0
	curbestcand = (0,0)
	for b in candidate:
		for a in range(-999,1001,2):
			if GPE.is_prime(a+b+1):
				n = 0
				while GPE.is_prime(n*n+n*a+b):
					n+=1
				if n > curbest:
					curbest = n
					curbestcand = (a,b)
	print(curbestcand[0]*curbestcand[1])



if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
