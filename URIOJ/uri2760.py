# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2760 - Entrada e Saída de String

def main():
    a, b, c = input(), input(), input()
    for _ in range(3):
        print("%s%s%s" % (a, b, c))
        a, b, c = b, c, a
    print("%s%s%s" % (a[0:10], b[0:10], c[0:10]))
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
