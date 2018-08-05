# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2759 - Entrada e Saída de Carácter

def main():
    a, b, c = input(), input(), input()
    for _ in range(3):
        print("A = %s, B = %s, C = %s" % (a, b, c))
        a, b, c = b, c, a
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
