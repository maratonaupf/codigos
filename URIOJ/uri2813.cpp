/*
 * Leonardo Deliyannis Constantin
 * URI 2813 - Evitando Chuva
*/

#include <stdio.h>

int main(){
    int N, C, E, c, e;
    char sd[8], sn[8];
    while(scanf("%d", &N) != EOF){
        C = E = c = e  = 0;
        while(N--){
            scanf(" %s %s", sd, sn);
            if(sd[0] == 'c'){
                e++;
                if(c > 0) c--;
                else C++;
            }
            if(sn[0] == 'c'){
                c++;
                if(e > 0) e--;
                else E++;
            }
        }
        printf("%d %d\n", C, E);
    }
    return 0;
}
