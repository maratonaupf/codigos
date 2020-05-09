/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1341/problem/B 
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 212345

typedef long long ll;

int main(){
    int t, n, i;
    int k, a[MAX];
    int p[MAX];
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for(i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        memset(p, 0, sizeof(p));
        for(i = 1; i <= n; i++){
            if(1 < i && i < n && a[i-1] < a[i] && a[i] > a[i+1])
                p[i] = 1;
            else
                p[i] = 0;
            p[i] += p[i-1];
        }
        int cur = -1, a1 = -1, a2 = -1;
        for(i = 1; i+k-2 <= n; i++){
            cur = p[i+k-2] - p[i] + 1;
            if(cur > a1){
                a1 = cur;
                a2 = i;
            }
        }
        printf("%d %d\n", a1, a2);
    }
    return 0;
}

