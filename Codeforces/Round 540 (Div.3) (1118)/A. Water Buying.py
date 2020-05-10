def main():
	q = int(input())
	for case in range(q):
		n,a,b = map(int, input().split())
		if n%2==0:
			print(min(n*a,n*b//2))
		else:
			print(min(n*a,(n-1)*b//2+a))


if __name__ == "__main__":
	main()
