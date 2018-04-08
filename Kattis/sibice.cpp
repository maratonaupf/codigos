/*
 * Leonardo Deliyannis Constantin
 * https://open.kattis.com/problems/sibice
*/

#include <stdio.h>
#include <math.h>

int main(){
    int N, W, H;
    int m;
    while(scanf("%d %d %d", &N, &W, &H) != EOF){
        while(N--){
            scanf("%d", &m);
            printf("%s\n", (double)m <= hypot(W, H) ? "DA" : "NE");
        }
    }
    return 0;
}
