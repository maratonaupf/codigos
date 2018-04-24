# -*- coding: utf-8 -*-
# Gera uma lista de numeros primos

lim = int(input())

for N in range(1, lim+1):
    if N > 1:
        ehPrimo = 1
    else:
        ehPrimo = 0
    for i in range(2, N):
        if N % i == 0:
            ehPrimo = 0
    if ehPrimo == 1:
        print(N)
