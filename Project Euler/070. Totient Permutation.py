import time
import Gratus_PE_Util as GPE
from math import *

def main():
    primes = GPE.sieve(int(10**3.5)+1)
    for a in range(len(primes)):
        for b in range(a+1,len(primes)):
            i = primes[a]
            j = primes[b]
            n = i*j
            ep = GPE.Euler_Phi(n,primes)
            if str(sorted(str(ep))) == str(sorted(str(n))):
                print(n,ep)

if __name__ == "__main__":
    start_time = time.time()
    main()
    print("--- %s seconds ---" % (time.time() - start_time))
