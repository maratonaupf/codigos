/*
 * Leonardo Deliyannis Constantin
 * URI 2715 - Dividindo os Trabalhos I
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define MAX 1020406

typedef long long ll;

ll v[MAX], l[MAX];

int main(){
    int N, i;
    ll total, ans;
    while(scanf("%d", &N) != EOF){
        total = 0LL;
        for(i = 0; i < N; i++){
            scanf("%lld", &v[i]);
            l[i] = v[i] + (i > 0 ? l[i-1] : 0);
            total += v[i];
        }
        ans = llabs(l[0] - (total - l[0]));
        for(i = 1; i < N; i++){
            ans = min(ans, llabs(l[i] - (total - l[i])));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
