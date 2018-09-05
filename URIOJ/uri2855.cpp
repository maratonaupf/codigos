/*
 * Leonardo Deliyannis Constantin
 * URI 2855 - Números de Sorte
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 305345

int main(){
    int N, M, i, idx;
    while(scanf("%d", &N) != EOF){
        vector<int> v(N+1, 0);
        for(i = 1; i <= N; i++){
            scanf("%d", &v[i]);
        }
        scanf("%d", &M);
        idx = lower_bound(v.begin(), v.end(), M) - v.begin();
        bool ans = true;
        for(i = 2; i < MAX && ans && idx >= i; i++){
            if(idx % i == 0)
                ans = false;
            idx -= (idx / i);   
        }
        printf("%c\n", ans ? 'Y' : 'N');
    }
    return 0;
}
