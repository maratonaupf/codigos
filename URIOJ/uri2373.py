# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2373 - Garçom

def main():
    N = int(input())
    ans = 0
    for _ in range(N):
        L, C = map(int, input().split())
        if L > C:
            ans += C
    print(ans)
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
