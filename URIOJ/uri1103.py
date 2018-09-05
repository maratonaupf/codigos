# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 1103 - Alarme Despertador

def main():
    h1, m1, h2, m2 = map(int, input().split())
    if h1 == 0 and m1 == 0 and h2 == 0 and m2 == 0:
        return
    m1 += h1 * 60
    m2 += h2 * 60
    ans = m2 - m1
    if ans >= 0:
        print(ans)
    else:
        print(ans + 24 * 60)
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
