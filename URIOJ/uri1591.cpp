/*
 * Leonardo Deliyannis Constantin
 * URI 1591 - Dia da Vovó
*/

#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
using namespace std;
#define MAX 52

int main(){
    int T, L, C, P;
    int i, j, k, c, tam;
    char grid[MAX][MAX];
    bool calc[MAX][MAX];
    char s[MAX];
    scanf("%d", &T);
    while(T--){
        scanf(" %d %d", &L, &C);
        memset(calc, 0, sizeof(calc));
        map<string, int> freq;
        for(i = 0; i < L; i++){
            scanf(" %s", grid[i]);
            for(j = 0; j < C; j++){
                if(!calc[i][j]){
                    calc[i][j] = 1;
                    freq[string(1, grid[i][j])]++;
                }
                for(k = j+1; k < C; k++){
                    tam = 0;
                    for(c = j; c <= k; c++){
                        s[tam++] = grid[i][c];
                    }
                    s[tam] = '\0';
                    freq[s]++;
                }
            }
        }
        for(i = 0; i < C; i++){
            for(j = 0; j < L; j++){
                if(!calc[j][i]){
                    calc[j][i] = 1;
                    freq[string(1, grid[j][i])]++;
                }
                for(k = j+1; k < L; k++){
                    tam = 0;
                    for(c = j; c <= k; c++){
                        s[tam++] = grid[c][i];
                    }
                    s[tam] = '\0';
                    freq[s]++;
                }
            }
        }
        scanf(" %d", &P);
        while(P--){
            scanf(" %s", s);
            printf("%d\n", freq[s]);
        }
    }
    return 0;
}
