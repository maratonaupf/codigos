# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# Kattis - Tarifa

import sys

def main():
    for line in sys.stdin:
        X = int(line)
        N = int(input())
        megabytes = X
        for _ in range(N):
            megabytes -= int(input())
            megabytes += X
        print(megabytes)
    
if __name__ == "__main__":
    main()
