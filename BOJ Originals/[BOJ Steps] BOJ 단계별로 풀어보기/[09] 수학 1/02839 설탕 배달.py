n = int(input())
three = 0
five = n//5
n %= 5

while five >=0:
    if n % 3 ==0:
        three = n//3
        n %= 3;
        break
    five -= 1
    n += 5
print(n==0 and (three + five) or -1)