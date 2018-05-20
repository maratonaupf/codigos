/*
 * Leonardo Deliyannis Constantin
 * URI 2369 - Conta de Água
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int N, ans;
    while(scanf("%d", &N) != EOF){
        ans = 7;
        N -= min(N, 10);
        ans += min(N, 20);
        N -= min(N, 20);
        ans += min(N, 70) * 2;
        N -= min(N, 70);
        ans += N*5;
        printf("%d\n", ans);
    }
    return 0;
}
