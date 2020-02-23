from sys import stdin

def input():
	return stdin.readline()[:-1]

def intput():
	return int(input().rstrip())

def sinput():
	return input().rstrip().split()

def intsput():
	return map(int, sinput())

def main():
	n, r = intsput()
	if n >= 10:
		print(r)
	else:
		print(r+(100*(10-n)))



if __name__ == '__main__':
	main()
