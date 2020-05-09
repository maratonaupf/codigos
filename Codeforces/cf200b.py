# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# https://codeforces.com/problemset/problem/200/B

def main():
    n = int(input())
    p = list(map(int, input().split()))
    soma = 0
    for i in range(0, n):
        soma += p[i]
    media = soma / n
    print("%.12f" % (media))
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
