#include<stdio.h>
#define MAX 112

int main(){
    int n, i, a[MAX], odd, even;
    while(scanf("%d", &n) != EOF){
        odd = even = 0;
        for(i = 0; i < n; i++){
            scanf("%d", a+i);
            if(a[i]&1){
                odd++;
            }else{
                even++;
            }
        }
        printf("%d\n", (odd > even) ? even : odd);
    }
    return 0;
}
