/*
 * Leonardo Deliyannis Constantin
 * URI 2590 - Sete
*/

#include <stdio.h>

int main(){
    int T, n;
    int p[] = { 1, 7, 9, 3 };
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        printf("%d\n", p[n%4]);
    }
    return 0;
}
