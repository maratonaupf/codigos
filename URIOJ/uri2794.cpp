/*
 * Leonardo Deliyannis Constantin
 * URI 2794 - Montes Claros
*/ 

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main(){
    int N, i;
    bool valid;
    while(scanf("%d", &N) != EOF){
        vector<ii> v(N, ii());
        for(i = 0; i < N; i++){
            scanf("%d %d", &v[i].first, &v[i].second);
        }
        sort(v.begin(), v.end());
        valid = true;
        for(i = 1; i < N && valid; i++)
            if(v[i-1].second < v[i].second)
                valid = false;
        printf("%c\n", valid ? 'S' : 'N');
    }
    return 0;
}
