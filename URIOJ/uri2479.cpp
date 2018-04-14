/*
 * Leonardo Deliyannis Constantin
 * URI 2479 - Ordenando a Lista de Crianças do Papai Noel
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 112
#define LEN 32

static int cmp(const void *p1, const void *p2){
    return strcmp((const char *) p1, (const char *) p2);
}

int main(){
    int N, i, good, bad;
    char c, v[MAX][LEN];
    while(scanf("%d", &N) != EOF){
        good = bad = 0;
        for(i = 0; i < N; i++){
            scanf(" %c %s", &c, v[i]);
            c == '+' ? good++ : bad++;
        }
        qsort(v, N, sizeof(v[0]), &cmp);
        for(i = 0; i < N; i++){
            printf("%s\n", v[i]);
        }
        printf("Se comportaram: %d | ", good);
        printf("Nao se comportaram: %d\n", bad);
    }
    return 0;
}
