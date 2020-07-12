import time


def main():
    p = 1
    q = 1
    ans = 0
    for c in range(1000):
        tmpp = p
        tmpq = q
        p = tmpp+2*tmpq
        q = tmpp+tmpq
        if len(str(p))>len(str(q)):
            ans+=1
    print(ans)


if __name__ == "__main__":
    start_time = time.time()
    main()
    print("--- %s seconds ---" % (time.time() - start_time))
