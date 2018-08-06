/*
 * Leonardo Deliyannis Constantin
 * URI 2191 - Saldo de Gols
*/

#include <stdio.h>

int main(){
    int N, i, T = 0;
    int gp, gc, sg, idx;
    int best, start, end;
    while(scanf("%d", &N), N){
        sg = start = end = best = 0;
        idx = 1;
        for(i = 1; i <= N; i++){
            scanf("%d %d", &gp, &gc);
            sg += gp - gc;
            if(sg < 0){
                sg = 0;
                idx = i+1;
            }
            else if(sg > best || (sg == best && i-idx > end-start)){
                best = sg;
                start = idx;
                end = i;
            }
        }
        printf("Teste %d\n", ++T);
        if(best <= 0)
            printf("nenhum\n\n");
        else
            printf("%d %d\n\n", start, end);
    }
    return 0;
}
