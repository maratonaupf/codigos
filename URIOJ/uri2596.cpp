/*
 * Leonardo Deliyannis Constantin
 * URI 2596 - Xenlonguinho
*/

#include <stdio.h>

int dividers(int N){
    int ans = 0;
    for(int i = 1; i*i <= N; i++){
        if(N % i == 0){
            ans++;
            if(i*i < N)
                ans++;
        }
    }
    return ans;
}

int solve(int N){
    int ans = 0;
    for(int i = 1; i <= N; i++)
        if(dividers(i) % 2 == 0)
            ans++;
    return ans;
}

int main(){
    int T, N;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        printf("%d\n", solve(N));
    }
    return 0;
}
