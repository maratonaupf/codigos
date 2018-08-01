/*
 * Leonardo Deliyannis Constantin
 * URI 2531 - Compras em FdI
*/

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
#define INF ((int)1e9)

typedef pair<int, int> ii;

class SegmentTree{
private: 
    vector<int> lo, hi, A;
    int n;
    int left(int p) { return (p << 1) + 1; }
    int right(int p){ return (p << 1) + 2; }
    void build(int p, int L, int R){
        if(L == R) lo[p] = hi[p] = A[L];
        else{
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2+1, R);
            lo[p] = min(lo[left(p)], lo[right(p)]);
            hi[p] = max(hi[left(p)], hi[right(p)]);
        }
    }
    ii query(int p, int L, int R, int i, int j){
        if(i > R || j < L) return {INF, -INF};
        if(L >= i && R <= j) return {lo[p], hi[p]};
        ii a = query(left(p), L, (L+R)/2, i, j);
        ii b = query(right(p), (L+R)/2+1, R, i, j);
        return {min(a.first, b.first), max(a.second, b.second)};
    }
    void update(int p, int L, int R, int idx, int newVal){
        int i = idx, j = idx;
        if(i > R || j < L) return;
        if(L == i && R == j){
            A[i] = newVal;
            lo[p] = hi[p] = A[L];
            return;
        }
        update(left(p), L, (L+R)/2, idx, newVal);
        update(right(p), (L+R)/2+1, R, idx, newVal);
        lo[p] = min(lo[left(p)], lo[right(p)]);
        hi[p] = max(hi[left(p)], hi[right(p)]);
    }
public:
    SegmentTree(const vector<int> &_A){
        A = _A; n = (int)A.size();
        lo.assign(4*n, 0);
        hi.assign(4*n, 0);
        build(0, 0, n-1);
    }
    int query(int i, int j){
        ii ans = query(0, 0, n-1, i, j);
        return ans.second - ans.first;
    }
    void update(int i, int val){
        update(0, 0, n-1, i, val);
    }
};

int main(){
    int N, Q, c, i, j;
    while(scanf("%d", &N) != EOF){
        vector<int> p(N, 0);
        for(i = 0; i < N; i++){
            scanf("%d", &p[i]);
        }
        SegmentTree st(p);
        scanf("%d", &Q);
        while(Q--){
            scanf("%d %d %d", &c, &i, &j);
            if(c == 1)
                st.update(i-1, j);
            else{
                i--, j--;
                printf("%d\n", st.query(min(i, j), max(i, j)));
            }
        }
    }
    return 0;
}
