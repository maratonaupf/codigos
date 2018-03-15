# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2728 - Grace Hopper, a Vovó do Cobol

import sys

def solve(line):
    ls = line.split('-')
    pat = 'cobol'
    i = 0
    for word in ls:
        w = word.lower()
        if w[0] != pat[i] and w[-1] != pat[i]:
            return 'BUG'
        i += 1
    return 'GRACE HOPPER'

for line in sys.stdin:
    print(solve(line[:-1]))

