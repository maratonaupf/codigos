# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2381 - Lista de Chamada

import sys

for line in sys.stdin:
    N = int(line.split()[0])
    k = int(line.split()[1])
    v = []
    for i in range(0, N):
    	v.append(input())
    v.sort()
    print(v[k-1])
