# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# OBI 2018 Nível Sênior, Fase 1 - Piso da escola

def main():
    while True:
        try:
            C = int(input())
            L = int(input())
            print(L*C + (L-1) * (C-1))
            print((L-1 + C-1) * 2)
        except EOFError:
            break
    
if __name__ == "__main__":
    main()
