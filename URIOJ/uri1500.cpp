/*
 * Leonardo Deliyannis Constantin
 * URI 1500 - Consultas Horríveis
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

class SegmentTree{
private:
    vector<ll> A, st, lz;
    int n;
    int left(int p) { return (p << 1) + 1; }
    int right(int p){ return (p << 1) + 2; }
    void propagate(int p, int L, int R){
        if(L != R){
            lz[left(p)] += lz[p];
            lz[right(p)] += lz[p];
        }
        st[p] += (R-L+1) * lz[p];
        lz[p] = 0;
    }
    void update(int p, int L, int R, int i, int j, ll val){
        propagate(p, L, R);
        if(L > j || R < i) return;
        if(L >= i && R <= j){
            if(L != R){
                lz[left(p)]  += val;
                lz[right(p)] += val;
            }
            st[p] += (R-L+1) * val;
            return;
        }
        update(left(p), L, (L+R)/2, i, j, val);
        update(right(p), (L+R)/2+1, R, i, j, val);
        st[p] = st[left(p)] + st[right(p)];
    }
    ll query(int p, int L, int R, int i, int j){
        propagate(p, L, R);
        if(L > j || R < i) return 0LL;
        if(L >= i && R <= j)
            return st[p];
        return query(left(p), L, (L+R)/2, i, j) +
            query(right(p), (L+R)/2+1, R, i, j);
    }
public:
    SegmentTree(const vector<ll> &_A){
        A = _A; n = (int)A.size();
        st.assign(4*n, 0LL);
        lz.assign(4*n, 0LL);
    }
    ll query(int i, int j){
        return query(0, 0, n-1, i, j);
    }
    void update(int i, int j, ll val){
        update(0, 0, n-1, i, j, val);
    }
};

int main(){
    int T, N, C;
    int o, p, q, v;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &C);
        SegmentTree st(vector<ll>(N, 0LL));
        while(C--){
            scanf("%d %d %d", &o, &p, &q);
            p--, q--;
            if(p > q) swap(p, q);
            if(o == 0){
                scanf("%d", &v);
                st.update(p, q, v);
            }
            else{
                printf("%lld\n", st.query(p, q));
            }
        }
    }
    return 0;
}
