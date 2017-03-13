#include<stdio.h>
#include<vector>
#define MAX 11234
using namespace std;

int main(){
    vector<bool> vivos;
    int N, R, placa, i, cont;
    while(scanf("%d %d", &N, &R) != EOF){
        vivos.assign(N+1, false);
        cont = 0;
        for(i = 0; i < R; i++){
            scanf("%d", &placa);
            vivos[placa] = true;
        }
        if(N == R){
            printf("*\n");
        }
        else{
            for(i = 1; i <= N; i++){
                if(!vivos[i]) printf("%d ", i);
            }
            printf("\n");
        }
        vivos.clear();
    }
    return 0;
}
