# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 1804 - Precisa-se de Matemáticos em Marte

from sys import stdin

def LSOne(S):
    return (S & (-S))

class FenwickTree:
    def __init__(self, n):
        self.__ft = [0] * (n + 1)
    
    def rsq(self, b):
        sum = 0
        while b > 0:
            sum += self.__ft[b]
            b -= LSOne(b)
        return sum
    
    def adjust(self, k, v):
        while k < len(self.__ft):
            self.__ft[k] += v
            k += LSOne(k)

def main():
    N = int(stdin.readline())
    v = list(map(int, stdin.readline().split()))
    bit = FenwickTree(N)
    for i in range(N):
        bit.adjust(i+1, v[i])
    for line in stdin:
        q, i = line.split()
        i = int(i)
        if q == 'a':
            bit.adjust(i, -v[i-1])
            v[i-1] = 0
        else:
            print(bit.rsq(i-1))
            
main()
