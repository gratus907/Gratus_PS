n, x = map(int, input().split())
a = [1]
b = [1]
for i in range(0,n) :
    a.append(a[i]*2+3)
    b.append(b[i]*2+1)

def task(n,x):
    if n==0 :
        if x <= 0 :
            return 0
        else :
            return 1
    elif x <= (1+a[n-1]) :
        return task(n-1,x-1)
    else :
        return b[n-1]+1+task(n-1,x-2-a[n-1])

print(task(n,x))
