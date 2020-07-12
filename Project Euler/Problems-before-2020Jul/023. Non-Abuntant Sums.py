from lib import Gratus_PE_Util as GPE
import time

def main():
	ans = 0
	abundants = []
	for x in range(1,28123):
		if sum(GPE.allDivisors(x)) > 2*x :
			abundants.append(x)
	for cand in range(1,28123):
		flag = 0
		for check in abundants:
			if check > cand:
				break
			if GPE.BinarySearch(cand-check,abundants) != -1:
				flag = 1
				break
		if flag == 0:
			ans += cand
	print(ans)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
