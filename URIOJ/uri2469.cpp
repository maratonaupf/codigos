/*
 * Leonardo Deliyannis Constantin
 * URI 2469 - Notas
*/

#include <stdio.h>
#include <map>
using namespace std;

int main(){
    int N, x, ans;
    while(scanf("%d", &N) != EOF){
        map<int, int> cnt;
        while(N--){
            scanf("%d", &x);
            cnt[x]++;
            if(cnt[x] > cnt[ans] || (cnt[x] == cnt[ans] && x > ans))
                ans = x;
        }
        printf("%d\n", ans);
    }
    return 0;
}
