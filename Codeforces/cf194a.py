# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# https://codeforces.com/contest/194/problem/A

def main():
    n, k = map(int, input().split())
    ans = 3*n - k
    if ans < 0:
        ans = 0
    print(ans)
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
