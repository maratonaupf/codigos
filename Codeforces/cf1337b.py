# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# https://codeforces.com/contest/1337/problem/B

def main():
    t = int(input())
    while t > 0:
        t -= 1
        x, n, m = map(int, input().split())
        while x > 20 and n > 0:
            x = x // 2 + 10
            n -= 1
        print("YES" if m * 10 >= x else "NO")

if __name__ == '__main__':
    main()
