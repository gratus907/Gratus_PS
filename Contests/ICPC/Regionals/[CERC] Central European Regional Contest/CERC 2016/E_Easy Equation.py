# For some reason, this solution seems to run slower in pypy3 than python
# Codeforces Gym submission couldn't fit in 0.5s TL in pypy, but python3 can.
# BOJ submission : python3 was 2~3x faster.
from sys import stdin
from collections import deque
def input():
	return stdin.readline()[:-1]

def intput():
	return int(input().rstrip())

def sinput():
	return input().rstrip().split()

def intsput():
	return map(int, sinput())

seen = {}
solseen = {}


def main():
	k, n = intsput()
	q = deque()
	q.append((0,1,k))
	ss = 0
	while len(q)>0:
		t = q[0]
		q.popleft()
		na = (t[1]*k+t[2]*k-t[0], t[1], t[2])
		if na not in solseen:
			q.append(na)
		if na[0]>0 and na[1]>0 and na[2]>0 and (na[0] not in seen and na[1] not in seen and na[2] not in seen):
			print(na[0], na[1], na[2])
			seen[na[0]] = 1
			seen[na[1]] = 1
			seen[na[2]] = 1
			solseen[na] = 1
			ss+=1
		if ss == n:
			break
		nb = (t[0], t[0]*k+t[2]*k-t[1], t[2])
		if nb not in solseen:
			q.append(nb)
		if nb[0] > 0 and nb[1] > 0 and nb[2] > 0 and (nb[0] not in seen and nb[1] not in seen and nb[2] not in seen):
			print(nb[0], nb[1], nb[2])
			seen[nb[0]] = 1
			seen[nb[1]] = 1
			seen[nb[2]] = 1
			solseen[nb] = 1
			ss += 1
		if ss == n:
			break
		nc = (t[0], t[1], t[0]*k+t[1]*k-t[2])
		if nc not in solseen:
			q.append(nc)
		if nc[0] > 0 and nc[1] > 0 and nc[2] > 0 and (nc[0] not in seen and nc[1] not in seen and nc[2] not in seen):
			print(nc[0], nc[1], nc[2])
			seen[nc[0]] = 1
			seen[nc[1]] = 1
			seen[nc[2]] = 1
			solseen[nc] = 1
			ss += 1
		if ss == n:
			break

if __name__ == '__main__':
	main()
