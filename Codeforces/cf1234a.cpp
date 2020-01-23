#include<stdio.h>
#define MAX 112

int main(){
    int t, n, i;
    int val, tot, avg;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        tot = 0;
        for(i = 0; i < n; i++){
            scanf("%d", &val);
            tot += val;
        }
        avg = tot / n;
        if(avg*n < tot)
            avg++;
        printf("%d\n", avg);
    }
    return 0;
}
