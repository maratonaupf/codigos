# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2339 - Aviões de Papel

import sys

def main():
    for line in sys.stdin:
        c, p, f = map(int, line.split())
        print('S' if p//c >= f else 'N')
    
if __name__ == "__main__":
    main()
