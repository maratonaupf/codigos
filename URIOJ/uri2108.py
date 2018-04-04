# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2108 - Contando Caracters

def main():
    biggest = ''
    while True:
        line = input()
        if line == '0':
            break
        seq = []
        for word in line.split():
            if len(word) >= len(biggest):
                biggest = word
            if seq: seq.append('-')
            seq.append(str(len(word)))
        print(''.join(seq))
    print("\nThe biggest word: " + biggest)
    
if __name__ == "__main__":
    main()
