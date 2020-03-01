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
	n = intput()
	print(n//2+(n%2))


if __name__ == '__main__':
	main()
