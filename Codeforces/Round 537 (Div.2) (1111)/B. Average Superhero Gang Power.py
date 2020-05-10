import time
from math import *

def main():
	n, k, m = map(int, input().split())
	power = sorted(list(map(int, input().split())))
	total = sum(power)
	maxpower = (total + min(m, n*k)) / n
	for i in range(min(n-1,m)):
		total -= power[i]
		tmp = (total + min(m-i-1, (n-i-1)*k))
		maxpower = max(maxpower, tmp/(n-i-1))
	print(maxpower)

if __name__ == "__main__":
	#start_time = time.time()
	main()
	#print("--- %s seconds ---" % (time.time() - start_time))
