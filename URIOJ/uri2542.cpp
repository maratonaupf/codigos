/*
 * Leonardo Deliyannis Constantin
 * URI 2542 - Iu-Di-Oh!
*/

#include <stdio.h>
#define MAX 112

int main(){
    int N, M, L, A;
    int i, j, cm, cl;
    int bm[MAX][MAX], bl[MAX][MAX];
    while(scanf("%d", &N) != EOF){
        scanf("%d %d", &M, &L);
        for(i = 0; i < M; i++)
            for(j = 0; j < N; j++)
                scanf("%d", &bm[i][j]);
        for(i = 0; i < L; i++)
            for(j = 0; j < N; j++)
                scanf("%d", &bl[i][j]);
        scanf("%d %d", &cm, &cl);
        scanf("%d",  &A);
        cm--; cl--; A--;
        printf("%s\n", bm[cm][A] > bl[cl][A] ? "Marcos" : bm[cm][A] == bl[cl][A] ? "Empate" : "Leonardo");
    }
    return 0;
}
