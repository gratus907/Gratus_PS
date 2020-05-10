import time
import Gratus_PE_Util as GPE
from math import *


def coin_change(n, coins):
	parts = [1]+[0]*n
	for c in coins:
		for i, x in enumerate(range(c, n+1)):
			parts[x] += parts[i]
	return parts[n]


def main():
	print(coin_change(200, [1,2,5,10,20,50,100,200]))


if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
