ls = []
for a in range (2, 101):
	for b in range (2, 101):
		ls.append(a**b)
print(len(set(ls)))
