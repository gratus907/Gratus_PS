from math import *
import re
def main():
	pref = ["c","j","n","m","t","s","l","d","qu"]
	vow = ["a","e","i","o","u","h"]
	lst = []
	cnt = 0
	S = input().split()
	for s in S:
		tmp = s.split('-')
		lst += tmp
	#print(lst)
	for s in lst:
		app = s.split("'")
		#print(app)
		if len(app) <2 :
			cnt += 1
		else:
			b = False
			for p in pref:
				if app[0] == p:
					b = True
					break
			if not b:
				cnt += 1
				continue
			if app[1][0] in vow:
				cnt += 2
			else:
				cnt += 1
	print(cnt)
if __name__ == '__main__':
	main()