import time
from lib import Gratus_PE_Util as GPE


def rotation(x, num):
    num = str(num)
    for i in range(x):
        tp = num[1:]+num[0]
        num = tp
    return num

def main():
    count = 0
    primes = GPE.sieve(10**6)
    for p in primes:
        u = len(str(p))
        flag = True
        for i in range(u):
            if GPE.BinarySearch(int(rotation(i,p)),primes)>-1:
                flag = True
            else:
                flag = False
                break
        if flag:
            print(p)
            count+=1
    print("answer is",count)

if __name__ == "__main__":
    start_time = time.time()
    main()
    print("--- %s seconds ---" % (time.time() - start_time))
