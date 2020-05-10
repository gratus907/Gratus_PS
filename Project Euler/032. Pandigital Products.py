import time
import Gratus_PE_Util as GPE
from math import *

def main():
	pandigital = "123456789"
	answer = 0
	ls = []
	for big in range(100,10000):
		for little in range(1,100):
			c = big*little
			s = str(c)+str(big)+str(little)
			u = ''.join(sorted(s))
			if u == pandigital and c not in ls:
				print(c,'=',big,'*',little)
				answer += c
				ls.append(c)
	print(answer)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
