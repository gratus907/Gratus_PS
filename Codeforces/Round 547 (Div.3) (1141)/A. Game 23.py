from math import *

def main():
    n, m = map(int, input().split())
    if (m%n)>0:
        print(-1)
        quit()
    else:
        step = 0
        while (m//n)%2==0:
            n *= 2
            step+=1
        while (m//n)%3==0:
            n *= 3
            step+=1
        if m==n:
            print(step)
        else:
            print(-1)



if __name__ == '__main__':
    main()
