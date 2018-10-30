# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# http://codeforces.com/problemset/problem/467/A

def main():
    n = int(input())
    count = 0
    for _ in range(n):
        p, q = map(int, input().split())
        if q-p >= 2:
            count = count + 1
    print(count)
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
