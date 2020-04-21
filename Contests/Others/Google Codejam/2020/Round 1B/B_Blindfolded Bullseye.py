import sys
t = 0
def interact(a, b):
    print(a, b)
    global t
    t += 1
    sys.stdout.flush()
    verdict = input()

    if verdict == "MISS":
        return 0
    elif verdict == "HIT":
        return 1
    elif verdict == "CENTER":
        return -1
    elif verdict == "WRONG":
        print("WRONG ANSWER")
        exit(0)
        
def main():
    global t
    t = 0
    M = 10**9
    C = M//5
    xcor = -1
    ycor = -1
    for i in range(-5, 6):
        for j in range(-5, 6):
            res = interact(C*i, C*j)
            if res == -1:
                return 
            elif res == 1:
                xcor = C*i
                ycor = C*j
    xlo = xcor
    xhi = 10**9+1
    xmid = (xlo+xhi)//2
    while xlo+1 < xhi:
        xmid = (xlo+xhi)//2
        res = interact(xmid, ycor)
        if res == -1:
            return
        elif res == 1:
            xlo = xmid
        else:
            xhi = xmid
    res = interact(xlo, ycor)
    if res == -1:
        return     
    if res == 0:
        xlo = xlo-1
    right = xlo
    xlo = -10**9
    xhi = xcor
    xmid = (xlo+xhi)//2
    while xlo+1 < xhi:
        xmid = (xlo+xhi)//2
        res = interact(xmid, ycor)
        if res == -1:
            return
        elif res == 1:
            xhi = xmid
        else:
            xlo = xmid    
    res = interact(xlo, ycor)
    if res == -1:
        return     
    if res == 0:
        xlo = xlo+1            
    left = xlo
    ylo = ycor
    yhi = 10**9+1
    ymid = (ylo+yhi)//2
    while ylo+1 < yhi:
        ymid = (ylo+yhi)//2
        res = interact(xcor, ymid)
        if res == -1:
            return
        elif res == 1:
            ylo = ymid
        else:
            yhi = ymid
    res = interact(xcor, ylo)
    if res == -1:
        return     
    if res == 0:
        ylo = ylo-1
    up = ylo
    ylo = -10**9
    yhi = ycor
    ymid = (ylo+yhi)//2
    while ylo+1 < yhi:
        ymid = (ylo+yhi)//2
        res = interact(xcor, ymid)
        if res == -1:
            return
        elif res == 1:
            yhi = ymid
        else:
            ylo = ymid    
    res = interact(xcor, ylo)
    if res == -1:
        return     
    if res == 0:
        ylo = ylo+1            
    down = ylo
    
    xans = (left+right)//2
    yans = (up+down)//2
    for i in range(-2, 3):
        for j in range(-2, 3):
            res = interact(xans+i, yans+j)
            if res == -1:
                return 
                
if __name__ == "__main__":
    T, A, B = map(int, input().split())
    t = 0
    for i in range(T):
        main()