/*
 * Leonardo Deliyannis Constantin
 * URI 2095 - Guerra
*/

#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
#define MAX 112345

int main(){
    int S, i, ans, q[MAX], n[MAX];
    while(scanf("%d", &S) != EOF){
        for(i = 0; i < S; i++){
            scanf("%d", &q[i]);
        }
        for(i = 0; i < S; i++){
            scanf("%d", &n[i]);
        }
        sort(q, q+S);
        sort(n, n+S);
        for(ans = 0, i = 0; i < S; i++)
            if(q[ans] < n[i])
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}
