#include<stdio.h>

typedef unsigned long long ull;

ull fat(ull n){
    ull ret = 1ULL;
    for(ull i = 2ULL; i <= n; i++){
        ret *= i;
    }
    return ret;
}

int main(){
    ull a, b;
    while(scanf("%llu %llu", &a, &b) != EOF){
        printf("%llu\n", fat(a) + fat(b));
    }
    return 0;
}
