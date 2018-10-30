# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# http://codeforces.com/problemset/problem/41/A

def reverse(a):
    return a[::-1]

def main():
    s = input()
    t = input()
    print("YES" if s == reverse(t) else "NO")       
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
