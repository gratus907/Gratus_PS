t = int(input())

for cases in range(0,t):
	len = int(input())
	num = input()
	if len==2:
		if num[0]>=num[1]:
			print("NO")
		else:
			print("YES")
			print(2)
			print(num[0], num[1])
	else:
		print("YES")
		print(2)
		print(num[0], num[1:])
