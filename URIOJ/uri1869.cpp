/*
 * Leonardo Deliyannis Constantin
 * URI 1869 - Base 32
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 11234

typedef unsigned long long ull;

void base32(ull N, char *s){
    int tam = 0, aux;
    do{
        aux = (int)(N % 32ULL);
        N /= 32ULL;
        s[tam++] = aux <= 9 ? '0' + aux : 'A' + (aux - 10);
    }while(N != 0ULL);
    reverse(s, s+tam);
    s[tam] = '\0';
    return;
}

int main(){
    ull N;
    char ans[MAX];
    while(scanf("%llu", &N), N != 0ULL){
        base32(N, ans);
        printf("%s\n", ans);
    }
    printf("0\n");
    return 0;
}
