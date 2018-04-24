# -*- coding: utf-8 -*-
# Verifica se um número é perfeito

N = int(input())

soma = 0
for i in range(1, N):
    if N % i == 0:
        soma = soma + i
        # soma += i

print('Soma dos divisores:', soma)
if soma == N:
    print(N, 'eh perfeito')
else:
    print(N, 'nao eh perfeito')
