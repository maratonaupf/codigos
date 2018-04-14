/*
 * Leonardo Deliyannis Constantin
 * URI 2719 - Quantas Viagens Fará o Noel?
*/

#include <stdio.h>

int main(){
    int T, N, M;
    int i, p, wt, trips;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        wt = 0;
        trips = 0;
        for(i = 0; i < N; i++){
            scanf("%d", &p);
            if(wt + p <= M)
                wt += p;
            else{
                wt = p;
                trips++;
            }
        }
        if(wt > 0)
            trips++;
        printf("%d\n", trips);
    }
    return 0;
}
