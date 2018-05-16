/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/978/problem/C
*/

#include <stdio.h>
#define MAX 212345

typedef long long ll;

int main(){
    int N, M, i;
    ll a[MAX], x, sum;
    while(scanf("%d %d", &N, &M) != EOF){
        for(i = 1; i <= N; i++){
            scanf("%lld", &a[i]);
        }
        sum = 0; i = 1;
        while(M--){
            scanf("%lld", &x);
            while(sum + a[i] < x){
                sum += a[i++];
            }
            printf("%d %lld\n", i, x-sum);
        }
    }
    return 0;
}
