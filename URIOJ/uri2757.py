# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2757 - Entrada e Saída de Números Inteiros

def main():
    a, b, c = int(input()), int(input()), int(input())
    print("A = %d, B = %d, C = %d" % (a, b, c))
    print("A = %10d, B = %10d, C = %10d" % (a, b, c))
    print("A = %010d, B = %010d, C = %010d" % (a, b, c))
    print("A = %-10d, B = %-10d, C = %-10d" % (a, b, c))
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
