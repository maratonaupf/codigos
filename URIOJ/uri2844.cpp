/*
 * Leonardo Deliyannis Constantin
 * URI 2844 - Escrita Rápida, o Duelo
*/

#include <stdio.h>
#include <string.h>
#define MAX 112345

int score(int a, int r, int e, int sz){
    return a*2 + r + e*sz;
}

int main(){
    int am, rm, em, av, rv, ev, m, v, sz;
    char s[MAX];
    while(scanf("%d %d %d", &am, &rm, &em) != EOF){
        scanf("%d %d %d ", &av, &rv, &ev);
        fgets(s, MAX, stdin);
        sz = (int)strlen(s)-1;
        m = score(am, rm, em, sz);
        v = score(av, rv, ev, sz);
        printf("%s\n", m < v ? "Matheus" : m == v ? "Empate" : "Vinicius");
    }
    return 0;
}
