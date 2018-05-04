# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 1253 - Cifra de César

N = int(input())

for i in range(0, N):
    s = input()
    p = int(input())
    nova = ''
    for j in range(0, len(s)):
        aux = ord(s[j]) - p
        if aux < 65:
            aux += 26
        nova += chr(aux)
    print(nova)
