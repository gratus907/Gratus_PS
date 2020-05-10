import time

def collatz(num):
	c = 0
	while True:
		if num % 2 == 0:
			num = num / 2
		else:
			num = num * 3 + 1
		if num == 1:
			return c + 1
		c+=1

start_time = time.time()
m = 0
for i in range (500001, 1000000, 2):
	v = collatz(i)
	if v >= m:
		ind = i
		m = v

print(ind)
print("--- %s seconds ---" % (time.time() - start_time))
# Time : 8 second
