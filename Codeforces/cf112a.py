# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# http://codeforces.com/problemset/problem/112/A

def main():
    a, b = input().lower(), input().lower()
    print(0 if a == b else -1 if a < b else 1)
    
if __name__ == '__main__':
    main()
