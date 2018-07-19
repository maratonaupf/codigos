# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 1895 - Jogo do Limite

def main():
    N, T, L = map(int, input().split())
    v = [0] * 2
    for i in range(N-1):
        S = int(input())
        dif = abs(T-S)
        if dif <= L:
            v[i%2] += dif
            T = S
    print("%d %d" % (v[0], v[1]))
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
