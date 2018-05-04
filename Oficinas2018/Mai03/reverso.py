N = int(input())

nomes = []
for i in range(N):
    nomes.append(input())

nomes.sort()

for nome in nomes:
    letras = []
    for letra in nome:
        letras.append(letra)
    letras.reverse()
    print(''.join(letras))
