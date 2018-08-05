# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2762 - Entrada e Saída 6

def main():
    a, b = map(int, input().split('.'))
    print("%d.%d" % (b, a))

if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
