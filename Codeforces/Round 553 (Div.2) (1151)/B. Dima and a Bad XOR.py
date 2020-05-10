def main():
	n, m = map(int, input().split())
	a = [[0] * m for i in range(n+5)]
	choose = [0]*1000
	choice = [[0,0] for i in range(n)]
	choiceind = []
	nochoice = 0
	for i in range(0,n):
		a[i] = list(map(int, input().split()))
		u = sorted(a[i])
		if u[m-1] == u[0]:
			choose[i] = 0
			nochoice += 1
		else:
			for j in range(1,m):
				if a[i][j] != a[i][j-1]:
					choice[i] = [j-1,j]
					choiceind.append(i)
	if nochoice==n:
		val = 0
		for i in range(n):
			val = (val^(a[i][0]))
		if val==0:
			print("NIE")
			quit()
		else:
			print("TAK")
			for x in range(n):
				print(1, end=" ")
	else:
		print("TAK")
		val = 0
		for i in range(n):
			if i in choiceind:
				choose[i] = choice[i][0]
		for i in range(n):
			val = (val ^ (a[i][choose[i]]))
		if val>0:
			for x in range(n):
				print(choose[x]+1, end=" ")
		else:
			choose[choiceind[0]] = choice[choiceind[0]][1]
			for x in range(n):
				print(choose[x]+1, end=" ")


if __name__ == '__main__':
	main()
