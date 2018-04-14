/*
 * Leonardo Deliyannis Constantin
 * URI 1870 - Ventiladores e Balões
*/

#include <stdio.h>
#define MAX 11

int L, C, P;
int power[MAX][MAX];

int left(int i, int P){
    while(power[i][P] == 0 && 1 < P)
        P--;
    return P;
}

int right(int i, int P){
    while(power[i][P] == 0 && P < C)
        P++;
    return P;
}

int main(){
    int i, j;
    bool alive;
    while(scanf("%d %d %d", &L, &C, &P), L != 0){
        for(i = 1; i <= L; i++){
            for(j = 1; j <= C; j++){
                scanf("%d", &power[i][j]);
            }
        }
        alive = true;
        for(i = 1; i <= L; i++){
            if(power[i][P] == 0)
                P += power[i][left(i, P)] - power[i][right(i, P)];
            if(power[i][P] != 0){
                printf("BOOM %d %d\n", i, P);
                alive = false;
                break;
            }
        }
        if(alive)
            printf("OUT %d\n", P);
    }
    return 0;
}
