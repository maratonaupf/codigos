/*
 * Leonardo Deliyannis Constantin
 * URI 2171 - Dividindo com Fink
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1123456

vector<int> v;
void setup(){
    v.push_back(1);
    for(int i = 2; v.back() < MAX; i++){
        v.push_back(i+v.back());
    }
}

int main(){
    int N, ans;
    setup();
    while(scanf("%d", &N), N){
        auto it = lower_bound(v.begin(), v.end(), N);
        if(*it > N)
            it--;
        ans = *it;
        printf("%d %d\n", ans, N-ans);
    }
    return 0;
}
