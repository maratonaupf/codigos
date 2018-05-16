/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/978/problem/D
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define MAX 112345

int main(){
    int N, i, b[MAX], a[MAX];
    int d0, d1, cnt, ans;
    bool possible;
    while(scanf("%d", &N) != EOF){
        for(i = 0; i < N; i++){
            scanf("%d", b+i);
        }
        if(N <= 2){
            printf("0\n");
            continue;
        }
        ans = -1;
        for(d0 = -1; d0 <= 1; d0++){
            for(d1 = -1; d1 <= 1; d1++){
                possible = true;
                a[0] = b[0] + d0;
                a[1] = b[1] + d1;
                cnt = abs(d0) + abs(d1);
                for(i = 2; i < N; i++){
                    a[i] = a[0] + i * (a[1] - a[0]);
                    if(abs(a[i] - b[i]) > 1){
                        possible = false;
                        //break;
                    }
                    else if(a[i] != b[i])
                        cnt++;
                }
                if(possible)
                    ans = (ans == -1) ? cnt : min(ans, cnt);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
