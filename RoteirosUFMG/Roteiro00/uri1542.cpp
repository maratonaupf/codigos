#include<stdio.h>

int main(){
    int Q, D, P, resp;
    while(scanf("%d", &Q), Q != 0){
        scanf("%d %d", &D, &P);
        resp = (Q*D*P)/(P-Q);
        printf("%d %s\n", resp, resp > 1 ? "paginas" : "pagina");
    }
    return 0;
}
