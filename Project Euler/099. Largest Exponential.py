from math import log
f = open("p099_base_exp.txt",'r')
a, b = 0, 0
val = 0
lind = 1
for line in f:
    base, exp = map(int,line.split(','))
    u = exp * log(base)
    if u>val:
        val = u
        a = base
        b =exp
        ans = lind
    lind+=1
print(ans)
