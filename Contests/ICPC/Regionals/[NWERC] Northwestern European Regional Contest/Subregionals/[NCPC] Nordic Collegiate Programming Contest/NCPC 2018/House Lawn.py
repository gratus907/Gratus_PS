l, m = map(int, input().split())
lst = []
curPrice = 10**10
for i in range(m):
    n, p, c, t, r = input().split(',')
    p, c, t, r = int(p), int(c), int(t), int(r)
    lst.append([n, p, c, t, r])
lst.sort(key = lambda x: x[1])
cnt = 0
for mow in lst:
    p, c, t, r = mow[1], mow[2], mow[3], mow[4]
    if c*t*10080 >= l*(t+r):
        if curPrice >= p:
            curPrice = p
            print(mow[0])
            cnt+=1
if cnt == 0:
    print("no such mower")