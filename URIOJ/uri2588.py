# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2588 - Jogo dos Palíndromos

import sys

def main():
    for line in sys.stdin:
        oc = [0] * 26
        for char in line[:-1]:
            oc[ord(char) - ord('a')] += 1
        ans = 0
        chance = True
        for cnt in oc:
            if cnt % 2 == 1:
                if chance:
                    chance = False
                else:
                    ans += 1
        print(ans)
    
main()
