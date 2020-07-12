import time
from math import *

fac = [1,1,2,6,24,120,720,5040,40320,362880]

def facsum(n):
	ls = map(int, str(n))
	fsum = 0
	for i in ls:
		fsum += fac[i]
	return fsum

def main():
	s = 0
	for i in range(10,5000000):
		if facsum(i)==i:
			s+=i
	print(s)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))

# 10 seconds Took
