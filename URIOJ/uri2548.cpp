/*
 * Leonardo Deliyannis Constantin
 * URI 2548 - Museu Virtual 3D
*/

#include <stdio.h>
#define MAX 1123

int main(){
    int N, M, x, ans;
    while(scanf("%d %d", &N, &M) != EOF){
        ans = 0;
        while(N--){
            scanf("%d", &x);
            if(M > N){
                ans += x;
                M--;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
