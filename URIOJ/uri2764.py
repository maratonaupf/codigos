# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2764 - Entrada e Saída de Data

def main():
    dd, mm, aa = input().split('/')
    print("%s/%s/%s" % (mm, dd, aa))
    print("%s/%s/%s" % (aa, mm, dd))
    print("%s-%s-%s" % (dd, mm, aa))
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
