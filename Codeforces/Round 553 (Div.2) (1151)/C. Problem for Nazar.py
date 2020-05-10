from math import *
import sys
import time
from statistics import *
from random import *
import bisect
sys.setrecursionlimit(10000000)

def f(a,b):
	ans = 0
	ans += (a * a)
	ans += ((b) * (b))
	ans += b
	ans %= (int(1e9 + 7))
	return int(ans)


def ev(n):
	ans = [0,0]
	x = 0
	u = 1
	flag = True
	while x<=n:
		x+=u
		if x>n:
			x-=u
			break
		if flag:
			ans[0]+=u
			flag = not flag
		else:
			ans[1]+=u
			flag = not flag
		u*=2
	if flag:
		ans[0] += (n-x)
	else:
		ans[1] += (n-x)
	return ans


def main():
	l, r = map(int, input().split())
	pl = ev(l-1)
	pr = ev(r)
	ans = f(pr[0], pr[1])-f(pl[0],pl[1])
	ans %= (int(1e9+7))
	print(int(ans))


if __name__ == '__main__':
	main()
