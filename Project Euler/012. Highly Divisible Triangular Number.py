import time
import math
def countDivisors(n):
	cnt = 0
	for i in range(1, (int(math.sqrt(n)) + 1)):
		if n % i == 0:
			if n / i == i:
				cnt = cnt + 1
			else:
				cnt = cnt + 2
	return cnt

def main():
	for n in range(1,100000):
		t = (int(n*(n+1)/2))
		if countDivisors(t)>500 :
			print(t)
			break

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
