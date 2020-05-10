import Gratus_PE_Util as GPE
import time

def main():
	c = 0
	for n in range(1,101):
		for r in range(1,n+1):
			u = GPE.Combination(n,r)
			if u > 1000000:
				c += 1
	print(c)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
