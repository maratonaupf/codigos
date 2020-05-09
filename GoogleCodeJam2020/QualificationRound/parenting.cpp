/*
 * Leonardo Deliyannis Constantin
 * Google Code Jam 2020 - Problem: Parenting Partnering Returns
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1123

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;

int main(){
    int t, x, n, i, st, e;
    int d[2], k;
    char s[MAX], c[2] = {'C', 'J'};
    scanf("%d", &t);
    for(x = 1; x <= t; x++){
        viii ac;
        scanf("%d", &n);
        for(i = 0; i < n; i++){
            scanf("%d %d", &st, &e);
            ac.push_back({{st, e}, i});
        }
        sort(ac.begin(), ac.end());
        memset(s, '-', n * sizeof(char));
        s[n] = '\0';
        d[0] = d[1] = 0;
        for(i = 0; i < n; i++){
            for(k = 0; k < 2; k++){
                if(d[k] <= ac[i].first.first){
                    d[k] = ac[i].first.second;
                    s[ac[i].second] = c[k];
                    break;
                }
            }
            if(s[ac[i].second] == '-'){
                strcpy(s, "IMPOSSIBLE");
                break;
            }
        }
        printf("Case #%d: %s\n", x, s);
    }
    return 0;
}
