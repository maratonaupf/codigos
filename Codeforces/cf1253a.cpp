#include<stdio.h>
#define MAX 112345

int main(){
    int t, n, i, a[MAX], b[MAX], d[MAX], cnt;
    bool ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ans = true;
        for(i = 1; i <= n; i++){
            scanf("%d", a+i);
        }
        d[0] = d[n+1] = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", b+i);
            d[i] = b[i] - a[i];
            if(d[i] < 0){
                ans = false;
            }
        }
        cnt = 0;
        for(i = 0; i <= n; i++){
            if(d[i] != d[i+1]){
                cnt++;
            }
        }
        if(cnt > 2)
            ans = false;
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}
