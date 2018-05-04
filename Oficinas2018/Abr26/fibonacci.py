# -*- coding: utf-8 -*-

N = int(input())

a = 0
b = 1

for i in range(N):
    print(a, end = ' ' if i < N-1 else '\n')
    c = a + b
    a = b
    b = c
