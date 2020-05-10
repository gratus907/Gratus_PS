import time
import Gratus_PE_Util as GPE
from math import *

def main():
    num = 1
    denum = 1
    for a in range(1,10):
        for b in range(1,a):
            for n in range(1,b):
                if (n*10+a)*b==(a*10+b)*n :
                    num *= n
                    denum *= b
    print(denum//(gcd(denum,num)))

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
