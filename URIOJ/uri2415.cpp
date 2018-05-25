/*
 * Leonardo Deliyannis Constantin
 * URI 2415 - Consecutivos
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int N, prev, curr, ans, mymax;
    while(scanf("%d", &N) != EOF){
        mymax = ans = 1;
        scanf("%d", &prev);
        while(--N){
            scanf("%d", &curr);
            if(prev == curr){
                ans++;
                mymax = max(mymax, ans);
            }
            else{
                ans = 1;
            }
            prev = curr;
        }
        printf("%d\n", mymax);
    }
    return 0;
}
