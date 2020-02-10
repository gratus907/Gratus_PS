def main():
    T = int(input())
    for tc in range(T):
        n = int(input())
        S = input()
        print("Case #"+str(tc+1)+": ",end='')
        for i in S:
            if i == "S":
                print("E",end='')
            else:
                print("S",end='')
        print()

main()