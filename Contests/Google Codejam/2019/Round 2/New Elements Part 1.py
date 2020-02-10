from math import *

def intersection(m1,k1,m2,k2):
	if m1==m2:
		return -1
	if k2==k1:
		return -1
	u = (k2-k1)/(m1-m2)

	if u<=0:
		return -1
	a = abs((k2 - k1))
	b = abs(m1 - m2)
	g = gcd(a,b)
	a = a//g
	b = b//g
	return a,b

def main():
	T = int(input())
	for tc in range(1, T+1):
		print("Case #"+str(tc)+":",end = ' ')
		cd = []
		jd = []
		sval = []
		n = int(input())

		for i in range(n):
			pp = list(map(int, input().split()))
			cd.append(pp[0])
			jd.append(pp[1])
		for i in range(n):
			for j in range(i+1,n):
				uu = intersection(cd[i],jd[i],cd[j],jd[j])
				if uu != -1:
					sval.append(uu)
		setval = set(sval)

		print(len(setval)+1)





if __name__ == "__main__":
	main()
