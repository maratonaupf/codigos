/*
 * Leonardo Deliyannis Constantin
 * URI 2884 - Interruptores
*/

#include <stdio.h>
#include <bitset>
#include <vector>
using namespace std;
#define MAX 1023

typedef bitset<MAX> bs;

int main(){
    int N, M, L, i, l, k;
    bs lamps;
    while(scanf("%d %d", &N, &M) != EOF){
        lamps.reset();
        scanf("%d", &L);
        for(i = 0; i < L; i++){
            scanf("%d", &l);
            lamps[l-1] = true;
        }
        vector<bs> in(N, bs());
        for(i = 0; i < N; i++){
            scanf("%d", &k);
            while(k--){
                scanf("%d", &l);
                in[i][l-1] = 1;
            }
        }
        for(i = 0; lamps.count() > 0 && i < N*N; i++){
            lamps ^= in[i%N];
        }
        printf("%d\n", lamps.count() ? -1 : i);
    }
    return 0;
}
