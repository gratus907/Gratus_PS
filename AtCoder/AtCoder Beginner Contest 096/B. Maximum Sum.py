a, b, c = map(int, input().split())
k = int(input())
print(a+b+c+max(a,b,c)*(2**k-1))
