import time
import math

def main():
	n = 4
	ans = n*n*3
	for i in range(1, n+1):
		for j in range(1, n+1):
			tmp = math.gcd(i, j)
			ans += min(j*tmp//i,(n-i)*tmp//j)*2
	print(ans)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
