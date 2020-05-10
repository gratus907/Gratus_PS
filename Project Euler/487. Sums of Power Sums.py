import time
import Gratus_PE_Util as GPE
import math
import numpy as np


def solve(n,k,p):
	fk = [0] * 10010
	sk = [0] * 10010
	for i in range(1, 10010):
		fk[i] = fk[i - 1] + pow(i, k, p)
		fk[i] %= p
	for i in range(1, 10010):
		sk[i] = sk[i - 1] + fk[i]
		sk[i] %= p
	print(fk)
	print(sk)
	print(fk[n])
	print(sk[n])
    for i in range()
	print(Lagrange(10**12,sk[0:k+2]))

def main():
	n,k,p = map(int, input().split())
	solve(n,k,p)




if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
