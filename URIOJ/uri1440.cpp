/*
 * Leonardo Deliyannis Constantin
 * URI 1440 - Praça de Alimentação
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

typedef pair<int, char> ic;

int main(){
    int N, i, h, m, s, in, ans;
    char c;
    while(scanf("%d", &N), N != 0){
        vector<ic> v;
        in = 0;
        for(i = 0; i < N; i++){
            scanf("%d:%d:%d %c ", &h, &m, &s, &c);
            if(c == 'E') in++;
            v.push_back({h*3600 + m*60 + s, c});
        }
        sort(v.begin(), v.end());
        for(i = 0; i < N; i++){
            if(v[i].second == '?'){
                if(in < N/2){
                    v[i].second = 'E';
                    in++;
                }
                else v[i].second = 'X';
            }
        }
        ans = in = 0;
        for(i = 0; i < N; i++){
            if(v[i].second == 'E') in++;
            if(v[i].second == 'X') in--;
            ans = max(in, ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
