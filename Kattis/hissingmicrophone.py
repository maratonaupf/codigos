# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# Kattis - Hissing Microphone

import sys

def main():
    for line in sys.stdin:
        print('hiss' if 'ss' in line else 'no hiss')
    
if __name__ == "__main__":
    main()
