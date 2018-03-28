/*
 * Leonardo Deliyannis Constantin
 * URI 2289 - Distância Hamming
*/

#include <stdio.h>

typedef unsigned long long ull;

int hamming(const ull &a, const ull &b){
    int ret = 0;
    for(ull i = 0ULL; i < 64ULL; i++){
        if((a & (1ULL << i)) != (b & (1ULL << i)))
            ret++;
    }
    return ret;
}

int main(){
    ull a, b;
    while(scanf("%llu %llu", &a, &b), a != 0ULL){
        printf("%d\n", hamming(a, b));
    }
    return 0;
}
