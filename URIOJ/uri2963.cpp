#include<stdio.h>
#define MAX 11234

int main(){
    int n, a[MAX], i, ans;
    while(scanf("%d", &n) != EOF){
        ans = 1;
        for(i = 0; i < n; i++){
            scanf("%d", a+i);
            if(i > 0 && a[i] > a[0])
                ans = 0;
        }
        printf("%c\n", ans ? 'S' : 'N');
    }
    return 0;
}
