/*
 * Leonardo Deliyannis Constantin
 * URI 2434 - Saldo do Vovô
*/

#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int main(){
    int N, cash, mov, ans;
    while(scanf("%d %d", &N, &cash) != EOF){
        ans = cash;
        while(N--){
            scanf("%d", &mov);
            cash += mov;
            ans = min(ans, cash);
        }
        printf("%d\n", ans);
    }
    return 0;
}
