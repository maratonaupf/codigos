/*
 * Leonardo Deliyannis Constantin
 * URI 1125 - Fórmula 1
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 112

struct pilot{
    int id, pts;  
};

bool cmp(pilot a, pilot b){
    if(a.pts != b.pts)
        return a.pts > b.pts;
    return a.id < b.id;
}

int main(){
    int G, P, r, i, S, K;
    int race[MAX][MAX];
    int score[MAX];
    pilot v[MAX];
    while(scanf("%d %d", &G, &P), G != 0){
        for(r = 0; r < G; r++){
            for(i = 0; i < P; i++){
                scanf("%d", &race[r][i]);
            }
        }
        scanf("%d", &S);
        while(S--){
            scanf("%d", &K);
            memset(score, 0, sizeof(score));
            for(i = 1; i <= K; i++){
                scanf("%d", &score[i]);
            }
            for(i = 0; i < P; i++){
                v[i].id = i+1;
                v[i].pts = 0;
                for(r = 0; r < G; r++){
                    v[i].pts += score[race[r][i]];
                }
            }
            sort(v, v+P, cmp);
            for(i = 0; v[0].pts == v[i].pts; i++){
                printf("%d%c", v[i].id, v[0].pts == v[i+1].pts ? ' ' : '\n');
            }
        }
    }
    return 0;
}
