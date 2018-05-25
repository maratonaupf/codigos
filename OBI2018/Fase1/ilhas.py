# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# OBI 2018, Nível Sênior, Fase 1 - Ilhas

from heapq import heappop, heappush
from collections import defaultdict
INFTO = 1123456789

def dijkstra(s):
    dist[s] = 0
    Q = [(0, s)] # inicia a fila com o vértice inicial - custo 0
    while Q: # enquanto houverem elementos na fila
        # Como a fila recebe uma dupla, retiramos em duas variáveis
        cost, u = heappop(Q) # retiramos da dupla o custo e o ID
        for i in range(len(LG[u])): # quantidade de vizinhos de u
            v = LG[u][i][0] # indice 0 do iésimo vizinho é seu ID
            w = LG[u][i][1] # indice 1 do iésimo vizinho é seu custo
            if dist[v] > dist[u] + w: # se a distância é mais curta
                dist[v] = dist[u] + w # se torna a distância atual
                heappush(Q, (dist[v], v)) # o vértice vai na fila para visita

V, E = map(int, input().split())
dist = [INFTO] * V
LG = defaultdict(list)    

for _ in range(E):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    LG[u].append((v, w))
    LG[v].append((u, w))

server = int(input()) - 1
dijkstra(server)
menor = INFTO
maior = -1

for u in range(len(dist)):
    d = dist[u]
    print(u+1, dist[u])
    if d != 0:
        menor = min(menor, d)
    if d != INFTO:
        maior = max(maior, d)

print(maior - menor)
