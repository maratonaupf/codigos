/*
 * Leonardo Deliyannis Constantin
 * URI 2247 - Cofrinhos da Vovó Vitória
*/

#include <stdio.h>

int main(){
    int N, a, b, ans, T = 0;
    while(scanf("%d", &N), N){
        printf("Teste %d\n", ++T);
        ans = 0;
        while(N--){
            scanf("%d %d", &a, &b);
            ans += a - b;
            printf("%d\n", ans);
        }
        printf("\n");
    }
    return 0;
}
