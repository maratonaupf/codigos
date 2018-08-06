/*
 * Leonardo Deliyannis Constantin
 * URI 2252 - Descobrindo Senha
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 10

struct key{
    double o;
    int idx;
};

bool cmp(const key &a, const key &b){
    if(a.o != b.o)
        return a.o > b.o;
    return a.idx < b.idx;
}

int main(){
    int N, i, T = 0;
    key v[MAX];
    while(scanf("%d", &N) != EOF){
        for(i = 0; i < 10; i++){
            scanf("%lf", &v[i].o);
            v[i].idx = i;
        }
        sort(v, v+10, cmp);
        printf("Caso %d: ", ++T);
        for(i = 0; i < N; i++){
            printf("%d", v[i].idx);
        }
        printf("\n");
    }
    return 0;
}
