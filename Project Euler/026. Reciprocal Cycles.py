import time
import Gratus_PE_Util as GPE
from math import *

def main():
	num = l = 1
	for n in range(3, 1000):
		if gcd(n,1000) != 1:
			continue
		p = 1
		while (10 ** p) % n != 1:
			p += 1
		if p > l:
			num, l = n, p

	print(num)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
