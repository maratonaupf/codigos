# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2630 - Escala de Cinza

def solve(method, R, G, B):
    if(method == 'eye'):
        return int(0.30*R + 0.59*G + 0.11*B)
    elif(method == 'mean'):
        return int((R + G + B) / 3.0)
    elif(method == 'max'):
        return max(R, G, B)
    return min(R, G, B)

def main():
    caseNo = 0
    T = int(input())
    for _ in range(T):
        method = input()
        line = input()
        R, G, B = [int(x) for x in line.split()]
        caseNo += 1
        print("Caso #{}: {}".format(caseNo, solve(method, R, G, B)))

main()
