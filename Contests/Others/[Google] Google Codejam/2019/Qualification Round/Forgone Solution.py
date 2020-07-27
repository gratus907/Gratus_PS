def main():
    T = int(input())
    for tc in range(T):
        N = int(input())
        sn = str(N)
        l = len(sn)
        a = ["0"]*l
        b = ["0"]*l
        for i in range(l):
            if sn[i]=='4':
                a[i] = "3"
                b[i] = "1"
            else:
                a[i] = str(int(sn[i]))
                b[i] = str(0)

        print("Case #"+str(tc+1)+": "+str(int("".join(a)))+" "+str(int("".join(b))))

main()