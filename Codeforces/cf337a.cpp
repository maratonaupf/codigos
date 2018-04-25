/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/337/A
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 51
#define INF ((int)1e9)

int main(){
    int n, m, i, ans;
    int f[MAX];
    while(scanf("%d %d", &n, &m) != EOF){
        for(i = 0; i < m; i++){
            scanf("%d", f+i);
        }
        sort(f, f+m);
        ans = INF;
        for(i = 0; i <= m-n; i++){
            ans = min(ans, f[i+n-1] - f[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
