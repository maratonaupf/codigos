# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 1254 - Substituição de Tag

from sys import stdin
import re

def solve(word, num, txt):
    stack = []
    ans = ''
    for j in range(0, len(txt)):
        if txt[j] == '<':
            if stack:
               ans += txt[stack[-1]:j] 
               stack.pop()
            stack.append(j)
        elif txt[j] == '>' and stack:
            prep = re.compile(re.escape(word), re.IGNORECASE)
            ans += prep.sub(num, txt[stack[-1]:j+1])
            stack.pop()
        elif not stack:
            ans += (txt[j])
                
    return ans

def main():
    for word in stdin:
        num = stdin.readline()
        txt = stdin.readline()
        print(solve(word[:-1], num[:-1], txt[:-1]))

main()
