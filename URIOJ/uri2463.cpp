/*
 * Leonardo Deliyannis Constantin
 * URI 2463 - Corredor
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 51234

int main(){
    int N, a, i;
    int sum, ans;
    while(scanf("%d", &N) != EOF){
        sum = ans = 0;
        for(i = 0; i < N; i++){
            scanf("%d", &a);
            sum += a;
            ans = max(ans, sum);
            if(sum < 0)
                sum = 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}
