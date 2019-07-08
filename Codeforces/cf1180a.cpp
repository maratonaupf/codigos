#include<stdio.h>

int main(){
    int n;
    int ans[112];
    ans[1] = 1;
    for(int i = 2; i < 112; i++){
        ans[i] = ans[i-1] + 4*(i-1);
    }
    while(scanf("%d", &n) != EOF){
        printf("%d\n", ans[n]);
    }
    return 0;
}
