/*
 * Leonardo Deliyannis Constantin
 * URI 2857 - Fluxo nos Vagões
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define LSOne(S) (S & (-S))

typedef vector<int> vi;

class FenwickTree{
private:
    vi ft;
public:
    FenwickTree(int N){ ft.assign(N+1, 0); }
    int rsq(int b){
        int sum = 0;
        while(b > 0){
            sum += ft[b];
            b -= LSOne(b);
        }
        return sum;
    }
    int rsq(int a, int b){
        return rsq(b) - (a == 1 ? 0 : rsq(a-1));
    }
    void update(int k, int v){
        for(; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
    }
};

int main(){
    int N, M, op, x, y, a, b, c, d, ans;
    while(scanf("%d %d", &N, &M) != EOF){
        FenwickTree ft(N);
        while(M--){
            scanf("%d", &op);
            if(op == 1){
                scanf("%d %d", &x, &y);
                ft.update(x, y);
            }else{
                scanf("%d %d %d %d", &a, &b, &c, &d);
                if(b < c || d < a)
                    ans = ft.rsq(a, b) + ft.rsq(c, d);
                else
                    ans = ft.rsq(min(a, c), max(b, d));
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
