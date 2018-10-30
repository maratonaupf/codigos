# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# http://codeforces.com/problemset/problem/208/A

def main():
    song = input().split("WUB")
    words = []
    for word in song:
        if word != '':
            words.append(word)
    words.append('')
    print(' '.join(words))
    
if __name__ == '__main__':
    while True:
        try:
            main()
        except EOFError:
            break
