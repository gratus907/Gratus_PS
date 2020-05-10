import time
from math import *


def main():
	f = open("p022_names.txt",'r')
	tmp = []
	name = []
	ans = 0
	for line in f:
		tmp = list(line.split(','))
	for el in tmp:
		name.append(el.strip('"'))
	name.sort()
	num = [0]*len(name)
	for i in range(len(name)):
		x = name[i]
		for c in x:
			num[i] += ord(c) - ord('A')+1
		num[i] *= (i+1)
		ans += num[i]
	print(ans)


if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
