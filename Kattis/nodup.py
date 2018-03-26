# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# Kattis - No Duplicates

from sys import stdin
from collections import Counter

def main():
    for line in stdin:
        nodup = True
        c = Counter()
        for word in line.split():
            c[word] += 1
            if c[word] > 1:
                nodup = False
                break
        print('yes' if nodup else 'no')
    
if __name__ == "__main__":
    main()
