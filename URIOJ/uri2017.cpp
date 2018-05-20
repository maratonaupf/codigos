/*
 * Leonardo Deliyannis Constantin
 * URI 2017 - Seis Strings
*/

#include <stdio.h>
#define LEN 112345

int main(){
    char x[LEN], s[LEN];
    int k, i, j, dist[5], ans;
    while(scanf("%s", x) != EOF){
        scanf("%d", &k);
        ans = 0;
        for(i = 0; i < 5; i++){
            scanf("%s", s);
            dist[i] = 0;
            for(j = 0; s[j]; j++){
                dist[i] += x[j] != s[j];
            }
            if(dist[i] < dist[ans])
                ans = i;
        }
        printf("%d\n", dist[ans] <= k ? ans+1 : -1);
        if(dist[ans] <= k)
            printf("%d\n", dist[ans]);
    }
    return 0;
}
