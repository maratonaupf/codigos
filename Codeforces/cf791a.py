# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# http://codeforces.com/problemset/problem/791/A

def main():
    a, b = map(int, input().split())
    anos = 0
    while a <= b:
        anos = anos + 1
        a = a * 3
        b = b * 2
    print(anos)
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
