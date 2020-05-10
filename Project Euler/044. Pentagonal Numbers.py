import time
import Gratus_PE_Util as GPE
import math

pentagonal_numbers = []

def is_pentagonal(x):
    if GPE.BinarySearch(x,pentagonal_numbers) == -1:
        return False
    else :
        return True


def main():
    for n in range(1,20000):
        pentagonal_numbers.append(n*(3*n-1)//2)

    for i in range(10000):
        for j in range(i+1,10000):
            if is_pentagonal(pentagonal_numbers[j]-pentagonal_numbers[i]) and is_pentagonal(pentagonal_numbers[i]+pentagonal_numbers[j]):
                print(i, j)
                print(pentagonal_numbers[i],pentagonal_numbers[j])
                print("Answer:",pentagonal_numbers[j]-pentagonal_numbers[i])
                return

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
