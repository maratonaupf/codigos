# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 1428 - Procurando Nessy

def main():
    T = int(input())
    for _ in range(T):
        n, m = map(int, input().split())
        print((n // 3) * (m // 3))
    
if __name__ == "__main__":
    main()
