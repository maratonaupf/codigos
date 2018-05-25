# -*- coding: utf-8 -*-

def main():
    m = [[0 for j in range(12)] 
            for i in range(12)]
    linha = int(input())
    op = input()
    
    for i in range(12):
        for j in range(12):
            m[i][j] = float(input())

    resp = 0
    for i in range(12):
        resp += m[linha][i]

    if op == 'M':
        resp /= 12.0

    print('{:.1f}'.format(resp))

if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
