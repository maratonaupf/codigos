# -*- coding: utf-8 -*-
# URI 1049 - Animal

a, b, c = input(), input(), input()

if a == 'vertebrado':
    if b == 'ave':
        if c == 'carnivoro':
            print('aguia')
        else:
            print('pomba')
    else:
        if c == 'onivoro':
            print('homem')
        else:
            print('vaca')
else:
    if b == 'inseto':
        if c == 'hematofago':
            print('pulga')
        else:
            print('lagarta')
    else:
        if c == 'hematofago':
            print('sanguessuga')
        else:
            print('minhoca')

