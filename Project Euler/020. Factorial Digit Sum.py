import time
from math import factorial

def main():
	print(sum(map(int,str(factorial(100)))))

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
