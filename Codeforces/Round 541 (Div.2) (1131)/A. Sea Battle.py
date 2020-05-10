def main():
    w1,h1,w2,h2 = map(int, input().split())
    s = max(w1,w2)
    u = h1+h2
    print(2*(s+u)+4)



if __name__ == "__main__":
    main()
