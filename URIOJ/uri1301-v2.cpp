/*
 * Leonardo Deliyannis Constantin
 * URI 1301 - Produto do Intervalo
*/

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
#define MAX 112345

typedef long long ll;

int cmp(int a, int b){
    return (a == 0 || b == 0) ? 0 : ((a < 0) ^ (b < 0)) ? -1 : 1;
}

class SegmentTree{
private:
    vector<int> st, A;
    int n;
    int left(int p) { return (p << 1) + 1; }
    int right(int p){ return (p << 1) + 2; }
    void build(int p, int L, int R){
        if(L == R) st[p] = A[L];
        else{
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2+1, R);
            st[p] = cmp(st[left(p)], st[right(p)]);
        }
    } 
    int query(int p, int L, int R, int i, int j){
        if(i > R || j < L) return 1LL;
        if(L >= i && R <= j) return st[p];
        return cmp(query(left(p), L, (L+R)/2, i, j), 
            query(right(p), (L+R)/2+1, R, i, j));
    }
    ll updatePoint(int p, int L, int R, int idx, ll newVal){
        int i = idx, j = idx;
        if(i > R || j < L) return st[p];
        if(L == i && R == j){
            A[i] = newVal;
            return st[p] = A[L];
        }
        return st[p] = 
            cmp(updatePoint(left(p), L, (L+R)/2, idx, newVal),
            updatePoint(right(p), (L+R)/2+1, R, idx, newVal));
    }
public:
    SegmentTree(const vector<int> &_A){
        A = _A; n = (int)A.size();
        st.assign(4*n, 0);
        build(0, 0, n-1);
    }
    int query(int i, int j){ return query(0, 0, n-1, i, j); }
    ll updatePoint(int idx, ll newVal){
        return updatePoint(0, 0, n-1, idx, newVal); }
};

int main(){
    int N, K, i, j;
    char c;
    while(scanf("%d %d", &N, &K) != EOF){
        vector<int> a(N, 1);
        for(i = 0; i < N; i++){
            scanf("%d", &a[i]);
            if(a[i] != 0) a[i] = (a[i] > 0) ? 1 : -1;
        }
        SegmentTree st(a);
        string ans = "";
        while(K--){
            scanf(" %c %d %d", &c, &i, &j);
            if(c == 'C'){
                st.updatePoint(i-1, j);
            }
            else{
                ll q = st.query(i-1, j-1);
                ans.push_back(q == 0 ? '0' : q > 0 ? '+' : '-');
            }
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
}
