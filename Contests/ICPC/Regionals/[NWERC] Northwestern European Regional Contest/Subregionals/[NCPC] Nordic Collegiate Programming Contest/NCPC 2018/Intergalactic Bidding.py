n, s = map(int, input().split())
bids = []
for i in range(n):
    pn, pm = input().split()
    pm = int(pm)
    bids.append([pm, pn])

bids.sort(key=lambda x : x[0], reverse=True)
cur = 0
cnt = 0
suc = False 
mark = [False] * 1010
for i in range(n):
    if cur + bids[i][0] <= s:
        cur += bids[i][0]
        mark[i] = True
        cnt+=1
    if cur == s:
        suc = True
        break
if not suc:
    print(0)
else:
    print(cnt)
    for j in range(n):
        if mark[j]:
            print(bids[j][1])