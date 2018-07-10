/*
 * Leonardo Deliyannis Constantin
 * URI 2807 - Iccanobif
*/ 

#include <stdio.h>
#define MAX 41

void generate(int fib[]){
    int i;
    for(i = 0; i < MAX; i++){
        fib[i] = (i <= 1) ? i : fib[i-1] + fib[i-2];
    }
}

int main(){
    int N;
    int fib[MAX];
    generate(fib);
    while(scanf("%d", &N) != EOF){
        for(; N > 0; N--){
            printf("%d%c", fib[N], N > 1 ? ' ' : '\n');
        }
    }
    return 0;
}
