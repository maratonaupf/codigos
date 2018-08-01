/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/1015/problem/C
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

bool cmp(ll a, ll b){
    return a > b;
}

int main(){
    int N, i;
    ll M, sum, a, b;
    while(scanf("%d %lld", &N, &M) != EOF){
        sum = 0;
        vector<ll> d(N, 0);
        for(i = 0; i < N; i++){
            scanf("%lld %lld", &a, &b);
            sum += a;
            d[i] = a-b;
        }
        sort(d.begin(), d.end(), cmp);
        for(i = 0; i < (int)d.size() && sum > M; i++)
            sum -= d[i];
        printf("%d\n", (sum <= M) ? i : -1);
    }
    return 0;
}
