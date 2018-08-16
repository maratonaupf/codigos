/*
 * Leonardo Deliyannis Constantin
 * URI 2390 - Escada Rolante
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int N, t, ans, b4;
    while(scanf("%d", &N) != EOF){
        ans = 10;
        b4 = -1;
        while(N--){
            scanf("%d", &t);
            if(b4 != -1){
                ans += min(10, t-b4);
            }
            b4 = t;
        }
        printf("%d\n", ans);
    }
    return 0;
}
