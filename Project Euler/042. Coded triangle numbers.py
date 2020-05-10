import time
import Gratus_PE_Util as GPE
from math import *

def euler_42(s):
	result = 0
	for c in s:
		result += ord(c)-ord('A')+1
	return result

def main():
	f = open("p042_words.txt",'r')
	ls = f.read().split(',')
	tmp = []
	ans = 0
	for x in ls:
		x = x.strip('"')
		v = euler_42(x)
		m = (sqrt(8*v+1) - 1) / 2
		if m==int(m):
			ans += 1
	print(ans)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
