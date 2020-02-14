import math

MAXN = 80808
mobi = [0]*(MAXN+10)
for i in range(1, MAXN+1):
	mobi[i] = 1

for i in range(2,int(MAXN**0.5)):
	if mobi[i] == 1:
		for j in range(i, MAXN+1, i):
			mobi[j] *= -i
		for j in range(i*i, MAXN+1, i*i):
			mobi[j] = 0
for i in range(2, MAXN+1):
	if mobi[i] == i:
		mobi[i] = 1
	elif mobi[i] == -i:
		mobi[i] = -1
	elif mobi[i] < 0:
		mobi[i] = 1
	elif mobi[i] > 0:
		mobi[i] = -1

for tc in range(5):
	n = int(input())
	ans = 0
	for i in range(1, n+1):
		ans += mobi[i]*((n//i)**4)
	print(ans)

