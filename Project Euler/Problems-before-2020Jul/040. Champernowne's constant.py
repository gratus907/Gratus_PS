import time

def main():
	i = 1
	s = ""
	while(len(s)<=1000500):
		s += (str(i))
		i += 1
	ans = 1
	s = list(map(int, s))
	s = [0] + s
	for i in range (7):
		ans *= s[10**i]
	print(ans)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))

# Approx 0.24 seconds took
