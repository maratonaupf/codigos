# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2408 - Vice-Campeão

import sys

def main():
    for line in sys.stdin:
        v = list(map(int, line.split()))
        v.sort()
        print(v[1])
    
if __name__ == "__main__":
    main()
