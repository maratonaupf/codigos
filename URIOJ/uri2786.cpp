/*
 * Leonardo Deliyannis Constantin
 * URI 2786 - Piso da Escola
*/ 

#include <stdio.h>

int main(){
    int l, c, q, t;
    while(scanf("%d %d", &l, &c) != EOF){
        q = l*c + (l-1)*(c-1);
        t = (l-1 + c-1) * 2;
        printf("%d\n%d\n", q, t);
    }
    return 0;
}
