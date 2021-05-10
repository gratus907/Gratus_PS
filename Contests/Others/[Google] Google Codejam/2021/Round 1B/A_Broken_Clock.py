from math import *
import sys
input = sys.stdin.readline
write = sys.stdout.write

fullrot = 360 * 12 * (10**10)
def nanosec_to_curtime(k : int):
    nano = k % 10**9
    k /= 10**9
    sec = k % 60
    k /= 60
    minute = k % 60
    k /= 60
    hr = k
    return hr, minute, sec, nano

def time_to_nanosec(h, m, s, n):
    T = 0
    T += (h * 60 * 60 * 10**9)
    T += (m * 60 * 10**9)
    T += (s * 10**9)
    T += n
    return T

def time_to_angle(h, m, s, n):
    T = time_to_nanosec(h, m, s, n)
    ht = T
    mt = T * 12
    st = T * 720
    return ht % fullrot, mt % fullrot, st % fullrot

def tmatch(a, b, c, h, m, s):
    offset = (fullrot + h - a) % fullrot
    if (b + offset) % fullrot == m % fullrot:
        if (c + offset) % fullrot == s % fullrot:
            return True
    return False

def cand_check(a, b, c, h, m, s):
    T = [
        tmatch(a, b, c, h, m, s),
        tmatch(a, c, b, h, m, s),
        tmatch(b, a, c, h, m, s),
        tmatch(b, c, a, h, m, s),
        tmatch(c, a, b, h, m, s),
        tmatch(c, b, a, h, m, s)
    ]
    for t in T:
        if t:
            return True
    return False

def main():
    A, B, C = map(int, input().split())
    for h in range(12):
        for m in range(60):
            for s in range(60):
                angles = time_to_angle(h, m, s, 0)
                if cand_check(A, B, C, angles[0], angles[1], angles[2]):
                    return h, m, s, 0

    return 0, 0, 0, 0

if __name__ == "__main__":
    TC = int(input())
    for tc in range(1, TC+1):
        write(f"Case #{tc}: ")
        res = main()
        write(f"{res[0]} {res[1]} {res[2]} {res[3]}\n")
