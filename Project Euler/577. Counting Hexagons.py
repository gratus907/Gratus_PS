import time
import Gratus_PE_Util as GPE
tn = []
def triangular_number(n):
	return n*(n+1)//2

def PE577_H(x):
	ans = 0
	for i in range(x//3+1):
		u = tn[x-3*i]
		u *= (i+1)
		ans += u
	return ans

def main():
	tn.append(0)
	for i in range(1,15000):
		tn.append(triangular_number(i))
	ans = 0
	for i in range(1,12344):
		ans += PE577_H(i)
	print(ans)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
