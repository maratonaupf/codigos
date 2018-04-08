# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 1893 - Fases da Lua

def main():
    while True:
        try:
            a, b = map(int, input().split())
            if b <= 2:
                print("nova")
            elif a < b and 3 <= b and b <= 96:
                print("crescente")
            elif 97 <= b:
                print("cheia")
            else:
                print("minguante")
        except EOFError:
            break
    
if __name__ == "__main__":
    main()
