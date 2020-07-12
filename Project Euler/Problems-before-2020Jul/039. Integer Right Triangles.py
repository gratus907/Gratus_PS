import time


def main():
	sols = [0]*1001
	for p in range(12,1002,2):
		for a in range(1,p//3):
			for b in range(a,p//2):
				c = p-a-b
				if c>a+b:
					continue
				else:
					if c*c == a*a+b*b:
						sols[p]+=1
					else:
						continue
	ind = 0
	maxi = 0
	for i in range(1001):
		if sols[i] > maxi:
			ind = i
			maxi = sols[i]
	print("Answer is %d with %d Solutions" %(ind,sols[ind]))


if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
