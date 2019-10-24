# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# https://codeforces.com/contest/1249/problem/A

def main():
    q = int(input())
    while q > 0:
        q = q - 1
        n = int(input())
        a = map(int, input().split())
        a = sorted(a)
        ans = 1
        for i in range(1, n):
            if a[i] - a[i-1] == 1:
                ans = 2
        print(ans)
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
