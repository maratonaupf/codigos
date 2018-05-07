/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/977/problem/C
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 212345

int main(){
    int n, k, i;
    int a[MAX];
    int ans, cnt;
    while(scanf("%d %d", &n, &k) != EOF){
        for(i = 0; i < n; i++){
            scanf("%d", a+i);
        }
        sort(a, a+n);
        ans = (k == 0) ? a[0] - 1 : a[k-1];
        cnt = 0;
        while(cnt < n && a[cnt] <= ans)
            cnt++;
        printf("%d\n", (ans < 1 || cnt != k) ? -1 : ans);
    }
    return 0;
}
