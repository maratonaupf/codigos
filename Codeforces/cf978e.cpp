/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/978/problem/E
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1123

int main(){
    int n, w, i, a;
    int b, minb, maxb;
    int lf, rg;
    while(scanf("%d %d", &n, &w) != EOF){
        scanf("%d", &b);
        minb = maxb = b;
        for(i = 1; i < n; i++){
            scanf("%d", &a);
            b += a;
            minb = min(b, minb);
            maxb = max(b, maxb);
        }
        lf = (minb <  0) ? -minb : 0;
        rg = (maxb <= 0) ? w : w - maxb;
        printf("%d\n", (maxb > w || lf > rg) ? 0 : rg-lf+1);
    }
    return 0;
}
