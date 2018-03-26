# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 1769 - CPF 1

from sys import stdin

def validateCPF(cpf):
    cpf = ''.join(cpf.split('.'))
    b1 = 0
    b2 = 0
    for i in range(0, 9):
        b1 += int(cpf[i]) * (i+1)
        b2 += int(cpf[i]) * (9-i)
    b1 %= 11
    b2 %= 11
    if b1 == 10:
        b1 = 0
    if b2 == 10:
        b2 = 0
    return b1 == int(cpf[10]) and b2 == int(cpf[11])

def main():
    for cpf in stdin:
        print('CPF {}valido'.format('' if validateCPF(cpf) else 'in'))
    
if __name__ == "__main__":
    main()
