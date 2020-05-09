/*
 * Leonardo Deliyannis Constantin
 * Google Code Jam 2020 - Problem: Vestigium
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 112

int main(){
    int t, n, i, j;
    int x, k, r, c;
    int m[MAX][MAX];
    int cnt[MAX];
    scanf("%d", &t);
    for(x = 1; x <= t; x++){
        scanf("%d", &n);
        k = r = c = 0;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                scanf("%d", &m[i][j]);
                if(i == j){
                    k += m[i][j];
                }
            }
        }
        for(i = 0; i < n; i++){
            memset(cnt, 0, sizeof(cnt));
            for(j = 0; j < n; j++){
                cnt[m[i][j]]++;
                if(cnt[m[i][j]] > 1){
                    r++;
                    break;
                }
            }
        }
        for(j = 0; j < n; j++){
            memset(cnt, 0, sizeof(cnt));
            for(i = 0; i < n; i++){
                cnt[m[i][j]]++;
                if(cnt[m[i][j]] > 1){
                    c++;
                    break;
                }
            }
        }
        printf("Case #%d: %d %d %d\n", x, k, r, c);
    }
    return 0;
}
