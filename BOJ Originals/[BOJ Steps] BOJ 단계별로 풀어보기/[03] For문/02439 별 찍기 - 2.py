N = input()
N = int(N)
k = 0
while k < N :
    k = k + 1
    a = '*'*k
    a = a.rjust(N, )
    print (a)