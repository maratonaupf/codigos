#include<bits/stdc++.h>
using namespace std;
#define MAX 1123

int main(){
    int k, i, n, a[MAX];
    int ht, wd, ans;
    scanf("%d", &k);
    while(k--){
        scanf("%d", &n);
        for(i = 0; i < n; i++){
            scanf("%d", a+i);
        }
        sort(a, a+n);
        ht = a[n-1];
        wd = 1;
        ans = 1;
        for(i = n-1; i >= 0; i--){
            ht = min(ht, a[i]);
            wd = n-i;
            ans = max(ans, min(ht, wd));
        }
        printf("%d\n", ans);
    }
    return 0;
}
