import Gratus_PE_Util as GPE
import time

def main():
	ans = 0
	for i in range(1,10):
		for x in range(1,1000):
			if len(str(pow(i,x))) == x:
				ans += 1
				print(i,x)
	print(ans)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
