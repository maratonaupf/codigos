# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 1578 - Matriz de Quadrados

def main():
    N = int(input())
    tc = 4;
    for num in range(4, N+4):
        if tc > 4:
            print('')
        M = int(input())
        m = []
        sz = [0] * M
        for i in range(M):
            m.append(list(map(int, input().split())))
            for j in range(M):
                m[i][j] *= m[i][j]
                sz[j] = max(sz[j], len(str(m[i][j])))
        print("Quadrado da matriz #%d:" % tc)
        for i in range(M):
            for j in range(M):
                print(str(m[i][j]).rjust(sz[j]), 
                    end=' ' if j < M-1 else '\n')
        tc += 1

if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
