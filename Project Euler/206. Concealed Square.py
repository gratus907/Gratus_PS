import time

def main():
	for i in range(1000000030, 1400000000, 100):
		s = str(i*i)
		if s[-3] != '9':
			continue
		if s[-5] != '8':
			continue
		if s[-7] != '7':
			continue
		if s[-9] != '6':
			continue
		if s[-11] != '5':
			continue
		if s[-13] != '4':
			continue
		if s[-15] != '3':
			continue
		if s[-17] != '2':
			continue
		if s[-19] != '1':
			continue
		print("answer is :", i)
	for i in range(1000000070, 1400000000, 100):
		s = str(i*i)
		if s[-3] != '9':
			continue
		if s[-5] != '8':
			continue
		if s[-7] != '7':
			continue
		if s[-9] != '6':
			continue
		if s[-11] != '5':
			continue
		if s[-13] != '4':
			continue
		if s[-15] != '3':
			continue
		if s[-17] != '2':
			continue
		if s[-19] != '1':
			continue
		print("answer is :", i)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
