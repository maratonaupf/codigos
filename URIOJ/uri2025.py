# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 2025 - Joulupukki

def main():
    N = int(input())
    for _ in range(N):
        ls = input().split()
        letter = []
        for word in ls:
            if word[1:-1] == 'oulupukk':
                letter.append('Joulupukki')
            elif word[1:-2] == 'oulupukk':
                letter.append('Joulupukki.')
            else:
                letter.append(word)
        print(' '.join(letter))
    
if __name__ == "__main__":
    main()
