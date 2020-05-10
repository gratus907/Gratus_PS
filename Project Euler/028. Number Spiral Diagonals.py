import time
import Gratus_PE_Util as GPE
from math import *


def main():
	s = 1
	for n in range(3, 1002, 2):
		s += 4 * n * n - 6 * n + 6
	print(s)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
