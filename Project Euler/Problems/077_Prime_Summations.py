from lib import Gratus_PE_Util as GPE
import time

def main():
	dp = [0]*1005
	dp[0] = 1
	primes = GPE.sieve(1000)
	for p in primes:
		for i in range(p, 1000):
			dp[i] += dp[i-p]
	for i in range(1,1000):
		if dp[i]>5000:
			print(f"ANSWER : {i}")
			break

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))