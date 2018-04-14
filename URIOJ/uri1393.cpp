/*
 * Leonardo Deliyannis Constantin
 * URI 1393 - Lajotas Hexagonais
*/

#include <stdio.h>
#define MAX 41

typedef unsigned long long ull;

int main(){
    int i;
    ull fib[MAX];
    fib[0] = fib[1] = 1ULL;
    for(i = 2; i < MAX; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    while(scanf("%d", &i), i != 0){
        printf("%llu\n", fib[i]);
    }
    return 0;
}
