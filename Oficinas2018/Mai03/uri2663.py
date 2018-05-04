# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2663 - Fase

N = int(input())
K = int(input())
v = []
for i in range(0, N):
    x = int(input())
    v.append(x)
v.sort(reverse = True)

while K < N and v[K-1] == v[K]:
    K += 1

print(K)
