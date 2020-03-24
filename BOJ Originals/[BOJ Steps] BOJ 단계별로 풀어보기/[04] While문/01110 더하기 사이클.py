def trial (lnum) :
    t = lnum[0] + lnum[1]
    if t < 10 :
        t = str(0) + str(t)
    lt= [int(x) for x in str(t)]
    newnum = lnum[1] * 10 + lt[1]
    return newnum

def intlist (number) :
    if number < 10 :
        number = str(0) + str(number)
    lnumber = [int(x) for x in str(number)]
    return lnumber


num = int(input())
first = num
lnum = intlist(num)
k = 1
while True :
    if trial(lnum) == first :
        break
    else : 
        lnum = intlist (trial (lnum))
        k = k + 1

print (k)
        