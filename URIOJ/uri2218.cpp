/*
 * Leonardo Deliyannis Constantin
 * URI 2218 - O Temível Evil-Son
*/

#include <stdio.h>

int f(int T){
    int i, ans;
    for(i = 0, ans = 1; i <= T; i++){
        ans += i;
    }
    return ans;
}

int main(){
    int N, T;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &T);
        printf("%d\n", f(T));
    }
    return 0;
}
