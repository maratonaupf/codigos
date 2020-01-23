/*
 * Leonardo Deliyannis Constantin
 * https://codeforces.com/contest/1279/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, i, a[3];
    bool ans;
    scanf("%d", &t);
    while(t--){
        for(i = 0; i < 3; i++){
            scanf("%d", a+i);
        }
        sort(a, a+3);
        ans = true;
        if(a[2] - 1 > a[1] + a[0])
            ans = false;
        printf("%s\n", ans ? "Yes" : "No");
    }
    return 0;
}
