# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2712 - Rodízio Veicular

import string

day = ['FAILURE', 'MONDAY', 'TUESDAY', 'WEDNESDAY', 'THURSDAY', 'FRIDAY']

def weekday(p):
    if len(p) != 8 or p[3] != '-':
        return 0
    for char in p[0:3]:
        if not char in string.ascii_uppercase:
            return 0
    for char in p[4:8]:
        if not char in string.digits:
            return 0
    return (ord(p[7]) - ord('1')) // 2 + 1 if p[7] != '0' else 5

def main():
    N = int(input())
    for _ in range(N):
        p = input()
        print(day[weekday(p)])
    
if __name__ == "__main__":
    main()
