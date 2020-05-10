import time
from math import *

def fifthsum(n):
	ls = map(int, str(n))
	fsum = 0
	for i in ls:
		fsum += pow(i,5)
	return fsum

def main():
	s = 0
	for i in range(10,999999):
		if fifthsum(i)==i:
			s+=i
	print(s)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
