a = 0
t = 0
li = []
while a < 10 :
    n = int (input())
    li.append (n % 42)
    a = a+1

exli = list(set(li))

print (len(exli))