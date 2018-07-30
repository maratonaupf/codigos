/*
 * Leonardo Deliyannis Constantin
 * URI 1301 - Produto do Intervalo
*/

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
#define MAX 112345
#define MOD ((ll)1e9+7LL)

typedef long long ll;

class SegmentTree{
private:
    vector<ll> st, A;
    int n;
    int left(int p){ return p << 1; }
    int right(int p){ return (p << 1) | 1; }
    void build(int p, int L, int R){
        if(L == R) st[p] = A[L];
        else{
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2+1, R);
            st[p] = ((st[left(p)] % MOD) * (st[right(p)] % MOD)) % MOD;
        }
    } 
    ll rpq(int p, int L, int R, int i, int j){
        if(i > R || j < L) return 1LL;
        if(L >= i && R <= j) return st[p];
        return (rpq(left(p), L, (L+R)/2, i, j) % MOD) *
            (rpq(right(p), (L+R)/2+1, R, i, j) % MOD) % MOD;
    }
    ll updatePoint(int p, int L, int R, int idx, ll newVal){
        int i = idx, j = idx;
        if(i > R || j < L) return st[p];
        if(L == i && R == j){
            A[i] = newVal;
            return st[p] = A[L];
        }
        return st[p] = 
            ((updatePoint(left(p), L, (L+R)/2, idx, newVal) % MOD) *
            (updatePoint(right(p), (L+R)/2+1, R, idx, newVal) % MOD)) % MOD;
    }
public:
    SegmentTree(const vector<ll> &_A){
        A = _A; n = (int)A.size();
        st.assign(4*n, 0LL);
        build(1, 0, n-1);
    }
    ll rpq(int i, int j){ return rpq(1, 0, n-1, i, j); }
    ll updatePoint(int idx, ll newVal){
        return updatePoint(1, 0, n-1, idx, newVal); }
};

int main(){
    int N, K, i, j;
    char c;
    while(scanf("%d %d", &N, &K) != EOF){
        vector<ll> a(N, 1LL);
        for(i = 0; i < N; i++){
            scanf("%lld", &a[i]);
        }
        SegmentTree st(a);
        string ans = "";
        while(K--){
            scanf(" %c %d %d", &c, &i, &j);
            if(c == 'C'){
                st.updatePoint(i-1, j);
            }
            else{
                ll q = st.rpq(i-1, j-1);
                ans.push_back(q == 0LL ? '0' : q > 0LL ? '+' : '-');
            }
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
}
