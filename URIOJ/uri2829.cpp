/*
 * Leonardo Deliyannis Constantin
 * URI 2829 - Maiúsculas, Por Quê?
*/

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#define MAX 51234
#define LEN 23

int cmp(const void *a, const void *b){
    int ret = strcasecmp((char*)a, (char*)b);
    if(ret == 0){
        return strcmp((char*)a, (char*)b);
    }
    return ret;
}

int main(){
    int N, i;
    char v[MAX][LEN];
    while(scanf("%d ", &N) != EOF){
        for(i = 0; i < N; i++){
            fgets(v[i], LEN, stdin);
        }
        qsort(v, N, sizeof(v[0]), &cmp);
        for(i = 0; i < N; i++){
            printf("%s", v[i]);
        }
    }
    return 0;
}
