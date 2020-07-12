from lib import Gratus_PE_Util as GPE
import time, itertools

def main():
    r = "7654321"
    for s in itertools.permutations(r):
        a = ''
        for x in s:
            a += (''.join(x))
        a = int(a)
        if GPE.is_prime(a):
            print(a)
            return

if __name__ == "__main__":
    start_time = time.time()
    main()
    print("--- %s seconds ---" % (time.time() - start_time))
