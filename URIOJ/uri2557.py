# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2557 - R+L=J

from sys import stdin

def main():
    for line in stdin:
        line, J = line.split('=')
        R, L = line.split('+')
        if(R == 'R'):
            print(int(J) - int(L))
        if(L == 'L'):
            print(int(J) - int(R))
        if(J[0] == 'J'):
            print(int(R) + int(L))
    
if __name__ == "__main__":
    main()
