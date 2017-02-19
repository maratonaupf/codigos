# -*- coding: utf-8 -*-

def expbin(a, n):
    if n == 0:
        return 1
    if n == 1:
        return a
    return expbin(a*a,  n/2) if n % 2 == 0 else a * expbin(a*a, (n-1) / 2)

T = input()
for i in range(0, T):
    arr = raw_input().split()
    c = int(arr[0])
    d = int(arr[1])
    ans = expbin(26, c) * expbin(10, d)
    print ans if ans > 1 else "0"

