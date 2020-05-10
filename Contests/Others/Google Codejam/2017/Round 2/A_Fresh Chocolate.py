import math
def solve():
    n, P = map(int, input().split())
    ls = list(map(int, input().split()))
    cnt = [0]*5
    for x in ls:
        cnt[x%P]+=1
    if P == 2:
        mg = cnt[1]//2
        cnt[1] %= 2
        return cnt[0]+mg+cnt[1]
    elif P == 3:
        mg = min(cnt[1], cnt[2])
        cnt[1] -= mg
        cnt[2] -= mg
        mg += cnt[1]//3+cnt[2]//3
        cnt[1] %= 3
        cnt[2] %= 3
        if cnt[1]>0 or cnt[2]>0:
            mg+=1
        return cnt[0]+mg
    elif P == 4:
        mg = min(cnt[1], cnt[3])
        cnt[1] -= mg
        cnt[3] -= mg
        mg += cnt[2]//2
        cnt[2] %= 2
        u = (cnt[2]*2+cnt[1]+cnt[3])
        return cnt[0]+mg+math.ceil(u/4)
    
    
T = int(input())
for tc in range(1, T+1):
    ans = solve()
    print("Case #{}: {}".format(tc,ans))
    