import time
from math import *
import itertools

def main():
	s = "0123456789"
	x = 0
	for i in itertools.permutations(s):
		x += 1
		if x == 1000000:
			for p in i:
				print(str(p),end='')
			print()

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
