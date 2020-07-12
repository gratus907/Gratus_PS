import time
from math import *

def main():
    fibo = [0,1,1]
    for i in range (3,10000):
        fibo.append(fibo[i-1]+fibo[i-2])
        if (len(str(fibo[i]))>=1000):
            print(i)
            quit()


if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
