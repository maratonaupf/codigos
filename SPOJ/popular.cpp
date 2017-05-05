/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/POPULAR/
*/

#include<stdio.h>
#include<string.h>
#define MAX 112

int main(){
    int votos[MAX];
    int n, i, j, voto;
    int maior;
    while(scanf("%d", &n), n != 0){
        memset(votos, 0, sizeof(votos));
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                scanf("%d", &voto);
                if(voto) votos[j]++;
            }
        }
        maior = 0;
        for(i = 0; i < n; i++){
            if(votos[i] > votos[maior]) maior = i;
        }
        printf("%d\n", votos[maior]);
    }
    return 0;
}
