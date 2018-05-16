/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/979/problem/B
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 112345

int main(){
    int N, i, j, b[3], c, ans;
    char s[MAX], name[3][6];
    int freq[128];
    strcpy(name[0], "Kuro");
    strcpy(name[1], "Shiro");
    strcpy(name[2], "Katie");
    while(scanf("%d", &N) != EOF){
        for(i = 0; i < 3; i++){
            scanf(" %s", s);
            b[i] = 0;
            memset(freq, 0, sizeof(freq));
            for(j = 0; s[j]; j++){
                c = s[j];
                b[i] = max(b[i], ++freq[c]);
            }
            b[i] = (N > 1) ? min(b[i] + N, j) : b[i] + (b[i] < j ? N : -N);
        }
        ans = -1;
        for(i = 0; i < 3; i++)
            if(b[i] > b[(i+1)%3] && b[i] > b[(i+2)%3])
                ans = i;
        printf("%s\n", ans == -1 ? "Draw" : name[ans]);
    }
    return 0;
}
