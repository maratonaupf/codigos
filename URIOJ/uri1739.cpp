/*
 * Leonardo Deliyannis Constantin
 * URI 1739 - Sequência de Threebonacci
*/

#include <stdio.h>
#define MAX 60

typedef unsigned long long ull;

bool has3(ull N){
    while(N > 0ULL){
        if(N % 10ULL == 3ULL) 
            return true;
        N /= 10ULL;
    }
    return false;
}

bool isValid(ull N){
    return N % 3ULL == 0 || has3(N);
}

void generate(ull *seq){
    int i = 0; 
    ull f1 = 1ULL, f2 = 2ULL, fib;
    while(i < MAX){
        fib = f1 + f2;
        if(isValid(fib))
            seq[i++] = fib;
        f1 = f2;
        f2 = fib;
    }
}

int main(){
    int N;
    ull seq[MAX];
    generate(seq);
    while(scanf("%d", &N) != EOF){
        printf("%llu\n", seq[N-1]);
    }
    return 0;
}
