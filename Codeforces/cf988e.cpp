/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/contest/988/problem/E
*/ 

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define LEN 21
#define INF ((int)1e9)

int main(){
    char s[LEN], t[LEN];
    int i, j, k, n, ans, cnt, nonZero, digs;
    while(scanf("%s", s) != EOF){
        n = (int)strlen(s);
        ans = INF;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i == j)
                    continue;
                strcpy(t, s);
                cnt = 0;
                for(k = i; k < n-1; k++){
                    swap(t[k], t[k+1]);
                    cnt++;
                }
                for(k = j - (j > i); k < n-2; k++){
                    swap(t[k], t[k+1]);
                    cnt++;
                }
                nonZero = -1;
                for(k = 0; k < n && nonZero == -1; k++)
                    if(t[k] != '0')
                        nonZero = k;
                for(k = nonZero; k > 0; k--){
                    swap(t[k], t[k-1]);
                    cnt++;
                }
                digs = (t[n-2]-'0') * 10 + (t[n-1]-'0');
                if(digs % 25 == 0)
                    ans = min(ans, cnt);
            }
        }
        printf("%d\n", ans != INF ? ans : -1);
    }
    return 0;
}
