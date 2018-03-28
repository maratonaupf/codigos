# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2493 - Jogo do Operador

from sys import stdin

class Expression:
    def __init__(self, v1, v2, result):
        self.v1 = v1
        self.v2 = v2
        self.result = result

def main():
    for line in stdin:
        T = int(line)
        ls = []
        for _ in range(T):
            vals, res = input().split('=')
            v1, v2 = map(int, vals.split())
            res = int(res)
            ls.append(Expression(v1, v2, res))
        names = []
        for _ in range(T):
            n, e, r = input().split()
            e = int(e) - 1
            add = ls[e].v1 + ls[e].v2 == ls[e].result
            sub = ls[e].v1 - ls[e].v2 == ls[e].result
            mul = ls[e].v1 * ls[e].v2 == ls[e].result
            imp = not (add or sub or mul)
            if r == '+': ans = add
            if r == '-': ans = sub
            if r == '*': ans = mul
            if r == 'I': ans = imp
            if not ans:
                names.append(n)
        if not names:
            print("You Shall All Pass!")
        elif len(names) == T:
            print("None Shall Pass!")
        else:
            names.sort()
            sz = len(names)
            for i in range(sz):
                print(names[i], end=(' ' if i < sz - 1 else '\n'))
    
if __name__ == "__main__":
    main()
