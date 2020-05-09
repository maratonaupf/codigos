/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1324/problem/B
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 5123

int main(){
    int t, n, i, a[MAX];
    bool ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ans = false;
        map<int, int> m;
        for(i = 0; i < n; i++){
            scanf("%d", a+i);
            if(!m.count(a[i])){
                m[a[i]] = i;
            }
            else{
                if(m[a[i]] < i-1){
                    ans = true;
                }
            }
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}
