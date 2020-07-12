import time
def dsum(x):
	return sum(map(int, str(x)))

def main():
	print(dsum(2**1000))


if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
