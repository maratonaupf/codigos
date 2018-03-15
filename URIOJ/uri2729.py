# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2729 - Lista de Compras

def main():
    N = int(input())
    for _ in range(N):
        ls = []
        for word in input().split():
            if not word in ls:
                ls.append(word)
        ls.sort()
        first = True
        for word in ls:
            if first:
                first = False
            else:
                print(' ', end='')
            print(word, end='')
        print()
    
main()
