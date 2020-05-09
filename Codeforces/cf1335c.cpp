/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1335/problem/C
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 212345
#define INF 0X

int main(){
    int t, n, i;
    int a[MAX];
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        map<int, int> cnt;
        int m = 0, diff = 0;
        for(i = 0; i < n; i++){
            scanf("%d", &a[i]);
            if(cnt[a[i]] == 0){
                diff++;
            }
            cnt[a[i]]++;
            if(cnt[a[i]] > cnt[m])
                m = a[i];
        }
        printf("%d\n", max(min(cnt[m], diff-1), min(cnt[m]-1, diff)));
    }
    return 0;
}
