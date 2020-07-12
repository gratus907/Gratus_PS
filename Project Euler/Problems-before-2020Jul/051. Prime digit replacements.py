import time
from lib import Gratus_PE_Util as GPE

pr = GPE.sieve(1000000)
vst = [False]*1000000

def isprime(x):
	return GPE.BinarySearch(x, pr) != -1

def gen(x, checklist):
	ls = [[]]*10
	for i in range(10):
		ls[i] = list(str(x))
	rls = [0]*10
	mk = False
	for i in range(10):
		for k in checklist:
			ls[i][k] = chr(ord('0')+i)
			if k == 0 and i == 0:
				mk = True
		rls[i] = int("".join(ls[i]))
	if mk:
		rls.remove(rls[0])
	return rls

def main():
	genp = 0
	tg = 8
	prls = []
	for i in range(1, 1000000):
		cand = [j for j in range(len(str(i)))]
		cd = GPE.powerset(cand)
		bst = 0
		for st in cd:
			if len(st)>0:
				cls = gen(i, st)
				ct = 0
				for p in cls:
					if isprime(p):
						ct += 1
					if ct == tg:
						print(cls[0])
						return

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))