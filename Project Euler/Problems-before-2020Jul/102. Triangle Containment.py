import time
from lib import Gratus_PE_Util as GPE


def main():
	f = open("102.txt",'r')
	ans = 0
	for line in f:
		cord = list(map(int,line.split(',')))
		a = GPE.Point(cord[0], cord[1])
		b = GPE.Point(cord[2], cord[3])
		c = GPE.Point(cord[4], cord[5])
		S =	GPE.triangle_area(a,b,c)
		s1 = GPE.triangle_area(a,b,GPE.Point(0,0))
		s2 = GPE.triangle_area(c,b,GPE.Point(0,0))
		s3 = GPE.triangle_area(a,c,GPE.Point(0,0))
		if S == s1+s2+s3:
			ans+=1
	print(ans)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
