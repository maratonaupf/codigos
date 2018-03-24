/*
 * Leonardo Deliyannis Constantin
 * URI 1607 - Avance as Letras
*/

#include <stdio.h>
#define MAX 11234

int solve(char *a, char *b){
    int ret = 0;
    for(int i = 0; a[i]; i++){
        ret += b[i] - (a[i] <= b[i] ? a[i] : a[i] - 26); 
    }
    return ret;
}

int main(){
    int N;
    char a[MAX], b[MAX];
    scanf("%d", &N);
    while(N--){
        scanf(" %s %s", a, b);
        printf("%d\n", solve(a, b));
    }
    return 0;
}
