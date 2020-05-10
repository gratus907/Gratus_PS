n = int(input())
l = []
sum = 0
for i in range (0,n) :
    x=int(input())
    l.append(x)
    sum+=x
l.sort()
sum-=l[n-1]//2
print(int(sum))
