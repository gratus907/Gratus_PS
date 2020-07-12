import time
from math import *

def checkpalindrome(S):
    l = len(S)
    for i in range(l//2):
        if (S[i] != S[l-i-1]):
            return False
    return True

def main():
    ans = 0
    for i in range(1,1000001):
        if checkpalindrome(str(i)) and checkpalindrome(str(bin(i))[2:]):
            ans += i
    print(ans)

if __name__ == "__main__":
	start_time = time.time()
	main()
	print("--- %s seconds ---" % (time.time() - start_time))
