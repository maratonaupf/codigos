/*
 * Leonardo Deliyannis Constantin
 * URI 2812 - Laércio
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T, N, i, x, p1, p2;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        vector<int> a;
        for(i = 0; i < N; i++){
            scanf("%d", &x);
            if(x&1)
                a.push_back(x);
        }
        sort(a.begin(), a.end());
        N = (int)a.size();
        p1 = 0, p2 = N-1;
        for(i = 0; i < N; i++){
            printf("%d%c", (i&1) ? a[p1++] : a[p2--], i < N-1 ? ' ' : '\n');
        }
        if(N == 0)
            printf("\n");
    }
    return 0;
}
