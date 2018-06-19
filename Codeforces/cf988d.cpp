/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/988/problem/D
*/ 

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 212345

int main(){
    int n, i, j, x[MAX];
    int m, ans, a[3];
    while(scanf("%d", &n) != EOF){
        for(i = 0; i < n; i++)
            scanf("%d", x+i);
        sort(x, x+n);
        ans = 1;
        for(m = 3; m >= 2 && ans == 1; m--){
            for(i = 0; i < n && ans == 1; i++){
                for(j = 0; j <= 30 && ans == 1; j++){
                    if(binary_search(x, x+n, x[i]+(1<<j))
                    && (m == 2 || binary_search(x, x+n, x[i]-(1<<j)))){
                        ans = m;
                        a[0] = a[1] = a[2] = x[i];
                        a[1] += (1<<j);
                        a[2] -= (1<<j);
                    }
                }
            }
        }
        if(ans == 1)
            a[0] = x[0];
        printf("%d\n", ans);
        for(i = 0; i < ans; i++){
            printf("%d%c", a[i], i < ans-1 ? ' ' : '\n');
        }
    }
    return 0;
}
