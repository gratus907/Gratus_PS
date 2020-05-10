def main():
	x,y,z = map(int, input().split())
	a,b,c = map(int, input().split())
	if x>a:
		print("NO")
		exit()
	else:
		a -= x
		u = a+b
		if y>u:
			print("NO")
			exit()
		else:
			u -= y
			u += c
			if z>u:
				print("NO")
				exit()
			else:
				print("YES")

if __name__ == "__main__":
	main()
