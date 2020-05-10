import time
import Gratus_PE_Util as GPE
import math

def main():
    plist = GPE.sieve(100000)
    twosq = []
    for i in range(1,300):
        twosq.append(i*i*2)
    for task in range(3,100000,2):
        if GPE.BinarySearch(task,plist)==-1:
            flag = False
            for p in plist:
                if task-p<=0:
                    break
                if GPE.BinarySearch(task-p,twosq) >= 0:
                    flag = True
                    break
            if not flag:
                print(task)
                return

        else:
            continue


if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
