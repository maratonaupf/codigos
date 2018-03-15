# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# https://open.kattis.com/problems/babelfish

import sys

ls = []

for line in sys.stdin:
	s = line.split(' ')
	if len(s) != 2:
		break
	ls.append((s[1], s[0]))
	
m = dict(ls)
	
for line in sys.stdin:
	print(m[line] if line in m else 'eh')
