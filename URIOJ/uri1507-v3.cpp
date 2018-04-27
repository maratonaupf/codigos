/*
 * Leonardo Deliyannis Constantin
 * URI 1507 - Subsequências
*/

#include <stdio.h>
#include <string.h>
#define LEN 112345

int main(){
    int N, Q, i, j;
    char s[LEN];
    char r[112];
    scanf("%d", &N);
    while(N--){
        scanf("%s", s);
        scanf("%d", &Q);
        while(Q--){
            scanf("%s", r);
            j = 0;
            for(i = 0; s[i] && r[j]; i++){
                if(s[i] == r[j])
                    j++;
            }
            printf("%s\n", j == (int)strlen(r) ? "Yes" : "No");       
        }
    }
    return 0;
}
