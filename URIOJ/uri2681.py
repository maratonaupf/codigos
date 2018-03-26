# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2681 - Macacos da Torre de Hanoi

from sys import stdin

MOD = 86400

def binpow(x, n):
    if n == 0:
        return 1
    y = 1
    while n > 1:
        if n&1:
            y *= x % MOD
            y %= MOD
        x *= x % MOD
        x %= MOD
        n //= 2
    return (x%MOD) * (y%MOD)

def main():
    for line in stdin:
        x = (binpow(2, int(line)) - 1) % MOD
        h = x / 3600
        x %= 3600
        m = x / 60
        x %= 60
        print("%02d:%02d:%02d" % (h, m, x))
    
if __name__ == "__main__":
    main()
