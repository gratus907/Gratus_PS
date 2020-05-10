def print_out():
	for i in range(n):
		for j in range(n):
			print(matrix[i][j], end = ' ')
		print()

n = int(input())
matrix = [[0] * n for i in range(n)]
ls = list(map(int,input().split()))
numbers = [0]*1020
for x in ls:
	numbers[x]+=1

if n%2==0:
	u = n//2
	tmp = 0
	ptr = 0
	able = True
	for i in range(1020):
		if numbers[i]%4>0:
			print("NO")
			quit()
	print("YES")

	while tmp<u*u:
		if numbers[ptr]==0:
			ptr+=1
			continue
		else:
			numbers[ptr]-=4
			matrix[tmp//u][tmp%u]=ptr
			tmp+=1
			continue
	for i in range(u):
		for j in range(u):
			matrix[n-i-1][n-j-1] = matrix[i][j]
			matrix[i][n-j-1] = matrix[i][j]
			matrix[n-i-1][j] = matrix[i][j]
	print_out()

else:
	u = n // 2
	tmp = 0
	ptr = 0


	while tmp < u * u:
		if ptr>1000:
			print("NO")
			quit()
		if numbers[ptr] <4 :
			ptr += 1
			continue
		else:
			numbers[ptr] -= 4
			matrix[tmp // u][tmp % u] = ptr
			tmp += 1
			continue
	for i in range(u):
		for j in range(u):
			matrix[n - i - 1][n - j - 1] = matrix[i][j]
			matrix[i][n - j - 1] = matrix[i][j]
			matrix[n - i - 1][j] = matrix[i][j]

	able = 0
	only = 0
	for i in range(1020):
		if numbers[i] % 2 > 0:
			able+=1
			only = i
	if able == 1:
		print("YES")
	else:
		print("NO")
		quit()
	var = u
	numbers[only] -= 1
	matrix[var][var] = only

	tmp = 0
	ptr = 0
	while tmp<u:
		if ptr>1000:
			print("NO")
			quit()
		else:
			if numbers[ptr]<2:
				ptr+=1
				continue
			else:
				numbers[ptr]-=2
				matrix[tmp][var] = ptr
				matrix[n-tmp-1][var] = ptr
				tmp+=1
				continue

	tmp = 0
	ptr = 0
	while tmp < u:
		if ptr > 1000:
			print("NO")
			quit()
		else:
			if numbers[ptr] < 2:
				ptr += 1
				continue
			else:
				numbers[ptr] -= 2
				matrix[var][tmp] = ptr
				matrix[var][n - tmp - 1] = ptr
				tmp += 1
				continue
	print_out()
