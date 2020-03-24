a,b = map(int, input().split())
k = 0
l = input().split()
while k < a :
    l[k] = int(l[k])
    k = k+1

k = 0
p = []
while k < a :
    if l[k] < b :
        p.append(l[k])
    else :
        None
    k = k + 1
str = " ".join(str(x) for x in p)
print (str)