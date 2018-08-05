# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2756 - Saída 10

def rhombus(N):
    for i in range(N):
        idx = min(i, N-1-i);
        c = chr(ord('A') + idx)
        s = [' '] * (4 + N//2 + idx)
        s[-1] = s[-(1+idx*2)] = c
        yield (''.join(s))

def main():
    for line in rhombus(9):
        print(line)
    
if __name__ == '__main__':
    main()
