N = []
x = int(input())
N.append(x)

for i in range(1, 10):
    N.append(N[i-1] * 2)
    
for i in range(len(N)):
    print('N[{}] = {}'.format(i, N[i]))
