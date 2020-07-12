import time
from lib import Gratus_PE_Util as GPE


def sq(x):
	return x*x

def main():
	ans = 10**7
	result = [False]*1001
	for i in range(1,1000):
		x = i
		while True:
			x = GPE.sum_on_digit(x,sq)
			if x is 89:
				result[i] = False
				break
			if x is 1:
				result[i] = True
				break
	for i in range(1,10**7+1):
		x = GPE.sum_on_digit(i,sq)
		if result[x]:
			ans -= 1
	print(ans)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
