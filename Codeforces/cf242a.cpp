/*
 * Leonardo Deliyannis Constantin
 * CodeForces 242A - Heads or Tails
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define PB push_back

typedef pair<int, int> ii;

int main(){
    int x, y, a, b;
    int i, j;
    while(scanf("%d %d %d %d", &x, &y, &a, &b) != EOF){
        vector<ii> v;
        vector<ii>::iterator it;
        for(i = max(a, b+1); i <= x; i++){
            for(j = b; j <= y && j < i; j++){
                v.PB(ii(i, j));
            }
        }
        printf("%lu\n", v.size());
        for(it = v.begin(); it != v.end(); ++it){
            printf("%d %d\n", it->first, it->second);
        }
    }
    return 0;
}
