/*
 * Leonardo Deliyannis Constantin
 * URI 2428 - Capital
*/

#include <stdio.h>

int main(){
    int a, b, c, d, ans;
    while(scanf("%d %d %d %d", &a, &b, &c, &d) != EOF){
        ans = (a*b == c*d || a*c == b*d || a*d == b*c);
        printf("%c\n", ans ? 'S' : 'N');
    }
    return 0;
}
