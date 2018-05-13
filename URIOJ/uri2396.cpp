/*
 * Leonardo Deliyannis Constantin
 * URI 2396 - Corrida
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

bool cmp(const ii &a, const ii &b){
    return a.first < b.first;
}

int main(){
    int N, M, i, j, lap;
    vector<ii> v;
    while(scanf("%d %d", &N, &M) != EOF){
        v.assign(N, ii(0, 0));
        for(i = 0; i < N; i++){
            v[i].first = 0; v[i].second = i+1;
            for(j = 0; j < M; j++){
                scanf("%d", &lap);
                v[i].first += lap;
            }
        }
        sort(v.begin(), v.end(), cmp);
        for(i = 0; i < 3; i++)
            printf("%d\n", v[i].second);
    }
    return 0;
}
