import time
from math import *

def comb(n, m):
	return factorial(n)//(factorial(m)*factorial(n-m))

def main():
	print(7 * (1- (comb(60,20)/comb(70,20))))

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))

#First 9 digits (6.818741802)
