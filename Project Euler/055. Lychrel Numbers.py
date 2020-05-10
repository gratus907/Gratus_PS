import time
import Gratus_PE_Util as GPE
from math import *

def int_palindrome(n):
	return GPE.check_palindrome(str(n))

def task_once(n):
	return n + int(str(n)[::-1])

def main():
	flags = [0]*10001
	for n in range(1,10001):
		c = 1
		var = task_once(n)
		while c<=50:
			if int_palindrome(var):
				flags[n] = 0
				break
			var = task_once(var)
			c+=1
		if c>50:
			flags[n] = 1
	print(sum(flags))


if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
