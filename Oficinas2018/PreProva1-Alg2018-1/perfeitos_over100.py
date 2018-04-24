# -*- coding: utf-8 -*-
# FUAQ gera e mostra os 4 maiores 
# numeros perfeitos maiores que 100

cont = 0
N = 100

while cont < 4:
    N = N + 1
    soma = 0
    for i in range(1, N):
        if N % i == 0:
            soma = soma + i
            # soma += i
    if soma == N:
        print(N)
        cont = cont + 1
        # cont += 1
