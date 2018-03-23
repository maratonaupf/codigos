# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 1036 - Fórmula de Bhaskara

import sys

def raiz(nutella):
    return nutella ** 0.5

for line in sys.stdin:
    a, b, c = map(float, line.split())
    delta = b**2 - 4*a*c
    if a == 0.0 or delta < 0.0:
        print('Impossivel calcular')
        continue
    r1 = (-b + raiz(delta)) / (2*a)
    r2 = (-b - raiz(delta)) / (2*a)
    print('R1 = {:.5f}'.format(r1))
    print('R2 = {:.5f}'.format(r2))
