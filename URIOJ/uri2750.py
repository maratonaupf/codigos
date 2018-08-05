# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2750 - Saída 4

def main():
    s = '---------------------------------------'
    t = '|  decimal  |  octal  |  Hexadecimal  |'
    print(s)
    print(t)
    print(s)
    for i in range(0, 16):
        print('|     %2d    |   %2o    |       %X       |' % (i, i, i))
    print(s)
    
if __name__ == '__main__':
    main()
