# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2144 - Bodybuilder

def repmax(w, r):
    return w * (1 + r/30)

casos = 0
soma = 0.0

while True:
    w1, w2, r = map(int, input().split())
    if w1 == 0 and w2 == 0 and r == 0:
        media = soma / casos
        if media > 40.0:
            print("\nAqui nois constroi fibra rapaz!" 
                + " Nao e agua com musculo!")
        break
    M = (repmax(w1, r) + repmax(w2, r)) / 2
    casos += 1
    soma += M
    if 1 <= M and M < 13:
        print("Nao vai da nao")
    elif M < 14:
        print("E 13")
    elif M < 40:
        print("Bora, hora do show! BIIR!")
    elif M <= 60:
        print("Ta saindo da jaula o monstro!")
    else:
        print("AQUI E BODYBUILDER!!")
    
