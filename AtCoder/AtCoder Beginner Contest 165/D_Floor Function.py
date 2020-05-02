a, b, n = map(int, input().split())
x = min(n, b-1)
print((a*x)//b-a*(x//b))
