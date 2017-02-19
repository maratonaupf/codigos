#include<stdio.h>

typedef long long ll;

int main(void){
    ll FP, FH;
    ll A, L;
    ll mol = 0;
    while(scanf("%lld %lld", &FP, &FH) != EOF){
        L = (FP*5 + FH*6) / 2;
        A = L + 2 - (FP+FH);
        printf("Molecula #%lld.:.\n", ++mol);
        printf("Possui %lld atomos e %lld ligacoes\n\n", A, L);
    }
    return 0;
}
