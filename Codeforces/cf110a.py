# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# http://codeforces.com/problemset/problem/110/A

def main():
    n = input()
    cnt = 0
    for digit in n:
        if digit == '4' or digit == '7':
            cnt += 1
    cnt = str(cnt)
    ans = True
    for digit in cnt:
        if digit != '4' and digit != '7':
            ans = False
            break
    print("YES" if ans else "NO")
        
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
