from sys import stdin

def input():
	return stdin.readline()[:-1]

def intput():
	return int(input())

def sinput():
	return input().split()

def intsput():
	return map(int, sinput())

def solve():
	n = intput()
	st = ""
	pl = []
	sl = []
	ml = ["X"]
	for i in range(n):
		cur = input()
		pref = suf = mid = ""
		j = 0
		jb = len(cur)-1
		while (cur[j]!="*"):
			pref = pref + cur[j]
			j+=1
		while (cur[jb]!="*"):
			suf = suf + cur[jb]
			jb-=1
		for k in range(j+1, jb):
			if (cur[k]!="*"):
				mid = mid + cur[k]
		pl.append(pref)
		sl.append(suf)
		ml.append(mid)
	pl = sorted(pl, key = lambda x:len(x), reverse = True)
	sl = sorted(sl, key = lambda x:len(x), reverse = True)
	fsuf = ""
	if len(pl)>0:
		fpref = pl[0]
		for prefs in pl:
			for j in range(len(prefs)):
				if prefs[j]!=fpref[j]:
					return "*"
		st = st + fpref
	for midstrs in ml:
		st = st + midstrs
	if len(sl)>0:
		fsuf = sl[0]
		for sufs in sl:
			for j in range(len(sufs)):
				if sufs[j]!=fsuf[j]:
					return "*"
		st = st + fsuf[::-1]
	return st

def main():
	TC = int(input())
	for tc in range(1, TC+1):
		print("Case #{}: ".format(tc)+solve())

main()