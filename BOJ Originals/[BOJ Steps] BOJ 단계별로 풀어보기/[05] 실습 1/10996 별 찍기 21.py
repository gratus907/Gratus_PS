def main():
	n = int(input())
	for i in range(2*n):
		if i%2 == 0:
			for x in range(n//2 + n%2):
				print("* ",end='')
		else:
			for x in range(n//2):
				print(" *",end='')
		print()

if __name__ == '__main__':
	main()