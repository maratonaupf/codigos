# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2710 - Juros do Projeto

import sys

def main():
    proj = 0
    for line in sys.stdin:
        x, y = map(float, line.split())
        ans = (y - x) * 100.0 / x
        proj += 1
        print("Projeto %d:" % proj)
        print("Percentual dos juros da aplicacao: %.2f %%\n" % ans)
    
if __name__ == "__main__":
    main()
