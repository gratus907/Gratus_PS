from math import factorial
def nonzero_last(x):
    s = reversed(str(factorial(x)))
    for i in s:
        if i != '0':
            return i
        
def fun(n):
    k = n//5
    r = n%5
    arr = [6, 2, 4, 8]
    if n < 100:
        return int(nonzero_last(n))
    else:
        S = (arr[k%4]*fun(k)*factorial(r))
        while S % 10 == 0:
            S /= 10
        return S % 10
    
n = int(input())
print(fun(n))