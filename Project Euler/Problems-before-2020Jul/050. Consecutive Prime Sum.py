import time
import Gratus_PE_Util as GPE

def main():
	prs = [0]*100000
	pr = GPE.sieve(1000000)
	lpr = len(pr)
	tpl = 0
	for i in range(1, lpr+1):
		prs[i] = prs[i-1] + pr[i-1]
		if prs[i] > 1000000:
			tpl = i
			break
	blen = 21
	bans = 953
	for i in range(1, tpl):
		for j in range(i+1, tpl):
			if j-i >= blen and GPE.BinarySearch(prs[j]-prs[i-1], pr) != -1:
				bans = prs[j]-prs[i-1]
				blen = max(blen, j-i)
	print(bans)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))