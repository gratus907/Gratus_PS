n=int(input())
a=list(input().split())
for i in range(n):
    if a[i][0]!='m':
        a[i]=int(a[i])
c=1
for i in range(n):
    if type(a[i])==int and a[i]!=i+1:
        print("something is fishy")
        c=0
        break
if c:
    print("makes sense")