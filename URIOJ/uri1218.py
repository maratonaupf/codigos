# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 1218 - Getline Three - Calçados

from sys import stdin

def main():
    cases = 0
    for num in stdin:
        N = int(num)
        ls = input().split()
        F, M = 0, 0
        for i in range(0, len(ls), 2):
            if(int(ls[i]) != N):
                continue
            if ls[i+1] == 'F':
                F += 1
            else:
                M += 1
        cases += 1
        if cases > 1: print("")
        print("Caso %d:" % cases)
        print("Pares Iguais: %d" % (F + M))
        print("F: %d" % F)
        print("M: %d" % M)
    
if __name__ == "__main__":
    main()
