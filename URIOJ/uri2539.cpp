/*
 * Leonardo Deliyannis Constantin
 * URI 2539 - High Five
*/

#include <stdio.h>
#include <vector>
using namespace std;
#define LSOne(S) (S & (-S))
#define MAX 112345

typedef long long ll;

class FenwickTree{
private:
    vector<int> ft;
public:
    FenwickTree(){}
    FenwickTree(int N){ ft.assign(N+1, 0); }
    ll rsq(int b){
        ll sum = 0;
        for(; b > 0; b -= LSOne(b)){
            sum += (ll) ft[b];
        }
        return sum;
    }
    ll rsq(int a, int b){
        return rsq(b) - (a == 1 ? 0LL : rsq(a-1));
    }
    void adjust(int k, int v){
        for(; k < (int)ft.size(); k += LSOne(k)){
            ft[k] += v;
        }
    }
};

int main(){
    int N, i;
    int v[MAX];
	while(scanf("%d", &N) != EOF){
        FenwickTree bit(N);
        for(i = 1; i <= N; i++){
            scanf("%d", &v[i]);
        }
        ll ans = 0;
        for(i = N; i >= 1; i--){
            bit.adjust(v[i], 1);
            ans += (ll) bit.rsq(v[i] + 1, N);
        }
        printf("%lld\n", ans);
    }
	return 0;
}
