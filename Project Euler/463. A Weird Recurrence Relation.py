import time
import Gratus_PE_Util as GPE
import math

valmap = {}

def f(k):
	if k in valmap:
		return valmap[k]
	print("Call ", k)
	if k%2 == 0:
		v = f(k//2)
		valmap[k] = v
		return v
	if k%4 == 1:
		u = (k-1)//4
		v = 2*f(2*u+1)-f(u)
		valmap[u] = v
		return v
	if k%4 == 3:
		u = (k-3)//4
		v = 3*f(2*u+1)-2*f(u)
		valmap[u] = v
		return v

def main():
	valmap[1] = 1
	valmap[3] = 3
	print((f(3**37))%(10**10))

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
