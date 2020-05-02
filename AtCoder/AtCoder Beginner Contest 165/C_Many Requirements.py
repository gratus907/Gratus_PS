from math import *
from itertools import combinations_with_replacement
ls = []
n, m, q = map(int, input().split())
for i in range(1, m+1):
	ls.append(i)
A = []
B = []
C = []
D = []
for i in range(q):
	a, b, c, d = map(int, input().split())
	A.append(a)
	B.append(b)
	C.append(c)
	D.append(d)
all_possible = list(combinations_with_replacement(ls, n))
max_score = 0
for each_comb in all_possible:
	combi = list(each_comb)
	score = 0
	for i in range(q):
		if combi[B[i]-1]-combi[A[i]-1] == C[i]:
			score += D[i]
	max_score = max(max_score, score)
print(max_score)
