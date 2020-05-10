import time
from math import *

def sumofDivisors(n):
	ans = 0
	for i in range(1,int(sqrt(n))+1):
		if n%i==0:
			if n == i*i:
				ans += i
			else:
				ans += i
				ans += n//i
	return (ans-n)


def main():
	sumdiv = []
	for i in range(10001):
		sumdiv.append(sumofDivisors(i))
	ans = 0
	for i in range(10001):
		if (sumdiv[i] > 10000):
			continue
		if (sumdiv[i] != i) and (sumdiv[sumdiv[i]] == i):
			ans += i
	print(ans)


if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
