/*
 * Leonardo Deliyannis Constantin
 * URI 2567 - Vírus
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1123

int main(){
    int N, i, a[MAX], p1, p2, ans;
    while(scanf("%d", &N) != EOF){
        for(i = 0; i < N; i++){
            scanf("%d", a+i);
        }
        sort(a, a+N);
        p1 = 0; p2 = N-1; ans = 0;
        while(p1 < p2){
            ans += a[p2] - a[p1];
            p1++;
            p2--;
        }
        printf("%d\n", ans);
    }
    return 0;
}
