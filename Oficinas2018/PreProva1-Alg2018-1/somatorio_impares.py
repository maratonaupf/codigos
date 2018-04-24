# -*- coding: utf-8 -*-

ini = int(input())
fim = int(input())

sigma = 0
for i in range(ini, fim+1):
    # if i % 2 == 1:
    if i % 2 != 0:
        # sigma = sigma + i
        sigma += i

print(sigma)
