/*
 * Leonardo Deliyannis Constantin
 * URI 1252 - Sort! Sort!! e Sort!!!
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 11234

int M;

inline bool isOdd(int x){
    return x%2 != 0;
}

bool cmp(int a, int b){
    int ma = a % M, mb = b % M;
    if(ma != mb)
        return ma < mb;
    if(isOdd(a) ^ isOdd(b))
        return isOdd(a);
    if(isOdd(a) & isOdd(b))
        return a > b;
    if(!(isOdd(a) | isOdd(b)))
        return a < b;
    return a < b;
}

int main(){
    int v[MAX];
    int N, i;
    while(scanf("%d %d", &N, &M), N != 0){
        for(i = 0; i < N; i++){
            scanf("%d", &v[i]);
        }
        sort(v, v+N, cmp);
        printf("%d %d\n", N, M);
        for(i = 0; i < N; i++){
            printf("%d\n", v[i]);
        }
    }
    printf("0 0\n");
    return 0;
}
