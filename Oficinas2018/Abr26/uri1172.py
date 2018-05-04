# -*- coding: utf-8 -*-

X = []

for i in range(0, 10):
    X.append(int(input()))
    if X[i] <= 0:
        X[i] = 1

for i in range(0, 10):
    print('X[{}] = {}'.format(i, X[i]))
    
    # print('X[' + str(i) + '] = ' + str(X[i]))
    
    # print('X[%d] = %d' % (i, X[i])) 
