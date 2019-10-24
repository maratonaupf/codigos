# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# https://codeforces.com/problemset/problem/705/A

def fraseDoHulk(n):
    if(n < 2):
        return ""
    if(n % 2 == 0):
        return fraseDoHulk(n-1) + " that I love"
    else:
        return fraseDoHulk(n-1) + " that I hate"

def main():
    n = int(input())
    print("I hate" + fraseDoHulk(n) + " it")
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
