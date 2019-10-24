#include <stdio.h>
#include <algorithm>
#define MAX 150112

int main(){
    int T, n, i, a[MAX], b[MAX], cnt;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        cnt = 0;
        for(i = 0; i < n; i++){
            scanf("%d", a+i);
        }
        b[n-1] = a[n-1];
        for(i = n-2; i >= 0; i--){
            b[i] = std::min(b[i+1], a[i]);
        }
        for(i = 0; i < n-1; i++){
            if(a[i] > b[i+1])
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
