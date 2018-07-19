# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2826 - Léxico

def main():
    a = input()
    b = input()
    if a > b:
        a, b = b, a
    print(a)
    print(b)
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
