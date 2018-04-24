# -*- coding: utf-8 -*-

N = int(input())

fat = 1
for i in range(1, N+1):
    fat = fat * i
    # fat *= i

print(fat)
