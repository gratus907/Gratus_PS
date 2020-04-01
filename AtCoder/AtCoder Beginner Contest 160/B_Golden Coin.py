t = int(input())
x = t//500
ans = 0
ans += x*1000
t -= x*500
x = t//5
ans += x*5
print(ans)
