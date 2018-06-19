/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/988/problem/B
*/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 112

bool sortable;

int cmp(const void *p1, const void *p2){
    char *a = (char*) p1, *b = (char*) p2;
    bool a_in_b = (strstr(b, a) != NULL);
    bool b_in_a = (strstr(a, b) != NULL);
    if(a_in_b) return -1;
    if(b_in_a) return  1;
    sortable = false;
    return strcmp(a, b);
}

int main(){
    int N, i;
    char a[MAX][MAX];
    while(scanf("%d", &N) != EOF){
        for(i = 0; i < N; i++){
            scanf("%s", a[i]);
        }
        sortable = true;
        qsort(a, N, sizeof(a[0]), cmp);
        if(sortable){
            printf("YES\n");
            for(i = 0; i < N; i++)
                printf("%s\n", a[i]);
        }
        else printf("NO\n");
    }
    return 0;
}
