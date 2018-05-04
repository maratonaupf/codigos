# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# URI 1168 - LED

N = int(input())

ql = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]

for i in range(0, N, 1):
    v = input()
    leds = 0
    for j in range(len(v)):
        # leds += ql[ord(v[j]) - ord('0')]
        leds += ql[int(v[j])]
    print('{} leds'.format(leds))
