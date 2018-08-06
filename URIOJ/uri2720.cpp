/*
 * Leonardo Deliyannis Constantin
 * URI 2720 - Presentes Grandes
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

bool cmp(const ii &a, const ii &b){
    if(a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main(){
    int T, N, K, i, h, w, l;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &K);
        vector<ii> v(N, ii());
        for(i = 0; i < N; i++){
            scanf("%d %d %d %d", &v[i].first, &h, &w, &l);
            v[i].second = h*w*l;
        }
        sort(v.begin(), v.end(), cmp);
        sort(v.begin(), v.begin() + K);
        for(i = 0; i < K; i++){
            printf("%d%c", v[i].first, i < K-1 ? ' ' : '\n');
        }
    }
    return 0;
}
