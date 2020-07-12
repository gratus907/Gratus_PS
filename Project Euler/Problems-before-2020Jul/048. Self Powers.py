import time


def main():
	ans = 0
	num = 10**10
	for i in range(1, 1001):
		ans += ((i**i)%num)
	ans %= num
	print(ans)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
