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
	ls = list(intsput())
	min_score = 10**30
	for i in range(1, 101):
		score = 0
		for j in ls:
			score += (j-i)**2
		if score < min_score:
			min_score = score
	print(min_score)



if __name__ == '__main__':
	main()
