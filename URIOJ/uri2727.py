# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2727 - Código Secreto

from sys import stdin
from string import ascii_lowercase

d = dict()

def prepare():
    i = 0
    for c in ascii_lowercase:
        dots = ' ' + '.' * ((i%3) + 1)
        pat = (dots * ((i // 3) + 1))[1:]
        d[pat] = c
        i += 1

def main():
    prepare()
    for line in stdin:
        N = int(line)
        for _ in range(N):
            print(d[stdin.readline()[:-1]])

main()
