from lib import Gratus_PE_Util as GPE
import time

def euler_381(p):
	n = int(p/24)
	u = p-24*n
	x = n*u+int((u*u-1)/24)
	return (9*x)%p


def main():
	ans = 0
	primes = GPE.sieve(10**8)
	for p in primes:
		if p==2 or p==3:
			continue
		ans += euler_381(p)
	print(ans)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
