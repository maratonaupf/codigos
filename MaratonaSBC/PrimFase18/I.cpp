/* 
 * [UPF] Skynet dos Pampas: Ômega
 * Maratona SBC 2018 - Interruptores
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1023

typedef bitset<MAX> bs;

int main(){
    int N, M, L, K, i, j;
    bs on;
    while(scanf("%d %d", &N, &M) != EOF){
        on.reset();
        scanf("%d", &L);
        for(i = 0; i < L; i++){
            scanf("%d", &j);
            on[j] = true;
        }
        vector<bs> flip(N);
        for(i = 0; i < N; i++){
            flip[i].reset();
            scanf("%d", &K);
            while(K--){
                scanf("%d", &j);
                flip[i][j] = true;
            }
        }
        int ans = 0;
        for(i = 0; on.count() != 0 && ans < N*N; i = (i+1)%N){
            on ^= flip[i];
            ans++;
        }
        printf("%d\n", ans < N*N ? ans : -1);
    }
    return 0;
}
