/*
 * Leonardo Deliyannis Constantin
 * URI 2344 - Notas da Prova
*/

#include <stdio.h>

int main(){
    int N;
    char ans;
    while(scanf("%d", &N) != EOF){
        ans = (N == 0) ? 'E' : 
            (N <= 35) ? 'D' : 
            (N <= 60) ? 'C' :
            (N <= 85) ? 'B' : 'A';
        printf("%c\n", ans);
    }
    return 0;
}
