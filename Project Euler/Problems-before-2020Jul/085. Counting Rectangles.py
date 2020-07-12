import time
from math import *

def comb(n, m):
	return factorial(n)//(factorial(m)*factorial(n-m))

def main():
	ans = 0
	target = 2000000
	n, m = 0, 0
	for i in range(1,100):
		for j in range(1,100):
			u = comb(i+1,2)*comb(j+1,2)
			if abs(target-u) <= abs(target-ans):
				ans = u
				n = i
				m = j
	print("answer =",n*m)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
