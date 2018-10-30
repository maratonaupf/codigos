# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# http://codeforces.com/problemset/problem/617/A

def main():
    x = int(input())
    ans = x//5 + (1 if x%5 > 0 else 0)
    print(ans)
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
