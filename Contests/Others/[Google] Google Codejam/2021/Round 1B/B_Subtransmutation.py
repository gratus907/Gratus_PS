from math import *
import sys
input = sys.stdin.readline
write = sys.stdout.write
MAX = 1000
def main():
    N, A, B = map(int, input().split())
    Ui = list(map(int, input().split()))
    U = [0] * (MAX+5)
    for i in range(len(Ui)):
        U[i+1] = Ui[i]
    for K in range(N, MAX+1):
        elements = [0] * (MAX+5)
        elements[K] = 1
        ok = True
        for i in range(K, 0, -1):
            if U[i] > elements[i]:
                ok = False
                break
            excess = elements[i] - U[i]
            if i > A:
                elements[i-A] += excess
            if i > B:
                elements[i-B] += excess
            elements[i] -= excess
        if ok:
            return K
    return "IMPOSSIBLE"


if __name__ == "__main__":
    TC = int(input())
    for tc in range(1, TC+1):
        write(f"Case #{tc}: ")
        res = main()
        write(f"{res}\n")