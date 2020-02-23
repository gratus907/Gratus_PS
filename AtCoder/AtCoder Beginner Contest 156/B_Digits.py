from sys import stdin
import math
def input():
	return stdin.readline()[:-1]

def intput():
	return int(input().rstrip())

def sinput():
	return input().rstrip().split()

def intsput():
	return map(int, sinput())

def main():
	n, k = intsput()
	for i in range(1,100):
		if k**i>n:
			print(i)
			return

if __name__ == '__main__':
	main()
