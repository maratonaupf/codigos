/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/580/A
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int N, i, curr, ant;
    int ans, temp;
    while(scanf("%d", &N) != EOF){
        ans = 1;
        temp = 1;
        for(i = 0; i < N; i++){
            scanf("%d", &curr);
            if(i > 0){
                if(ant <= curr)
                    temp++;
                else
                    temp = 1;
                ans = max(ans, temp);
            }
            ant = curr;
        }
        printf("%d\n", ans);
    }
    return 0;
}
