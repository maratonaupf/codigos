/*
 * Leonardo Deliyannis Constantin
 * URI 2027 - Aposta com Noel
*/

#include <stdio.h>
#define MAX 112

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a%b);
}

int main(){
    int r, n, cnt = 0;
    int ans[MAX];
    while(scanf("%d %d", &r, &n) != EOF){
        ans[cnt] = gcd(r, n);
        printf("%s\n", ans[cnt++] > 5 ? "Noel" : "Gnomos");
    }
    while(cnt--)
        printf("%d ", ans[cnt]);
    printf("\n");
    return 0;
}
