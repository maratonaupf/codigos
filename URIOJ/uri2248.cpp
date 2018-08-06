/*
 * Leonardo Deliyannis Constantin
 * URI 2248 - Estágio
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int main(){
    int N, i, a, n, best, klass = 0;
    while(scanf("%d", &N), N){
        best = 0;
        vector<vi> reg(112, vi());
        for(i = 0; i < N; i++){
            scanf("%d %d", &a, &n);
            reg[n].push_back(a);
            best = max(best, n);
        }
        printf("Turma %d\n", ++klass);
        for(i = 0; i < (int)reg[best].size(); i++){
            printf("%d ", reg[best][i]);
        }
        printf("\n\n");
    }
    return 0;
}
