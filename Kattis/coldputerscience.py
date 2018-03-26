# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# Kattis - Cold-Puter Science

import sys

def main():
    for line in sys.stdin:
        N = int(line)
        temps = list(map(int, input().split()))
        harshDays = 0
        for temp in temps:
            if temp < 0:
                harshDays += 1
        print(harshDays)
    
if __name__ == "__main__":
    main()
