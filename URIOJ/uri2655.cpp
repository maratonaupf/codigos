/*
 * Leonardo Deliyannis Constantin
 * URI 2655 - Trilha Perigosa
*/

#include <stdio.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

inline ll comp(ll a, ll b){ return a | b; }

class SegmentTree{
private:
    vll st, A;
    int size;
#define left(p)  ((p << 1) | 1)
#define right(p) ((p << 1) + 2)
    void build(int p, int l, int r){
        if(l == r) st[p] = A[l];
        else{
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2+1, r);
            st[p] = comp(st[left(p)], st[right(p)]);
        }
    }
    ll query(int p, int l, int r, int a, int b){
        if(a > r || b < l) return 0LL;
        if(l >= a && r <= b) return st[p];
        return comp(query(left(p), l, (l+r)/2, a, b),
            query(right(p), (l+r)/2+1, r, a, b));
    }
    void update(int p, int l, int r, int ind, ll v){
        if(ind > r || ind < l) return;
        else if(l == ind && r == ind){
            st[p] &= ~A[ind];
            A[ind] = v;
            st[p] |= A[l];
        }else{
            update(left(p), l, (l+r)/2, ind, v);
            update(right(p), (l+r)/2+1, r, ind, v);
            st[p] = comp(st[left(p)], st[right(p)]);
        }
    }
public:
    SegmentTree(vll &_A){
        A = _A;
        size = A.size();
        st.assign(4*size, 0LL);
        build(0, 0, size-1);
    }
    int query(int a, int b){
        return __builtin_popcountll(query(0, 0, size-1, a, b));
    }
    void update(int ind, ll v){
        update(0, 0, size-1, ind, v);
    }
};

int main(){
    int N, Q, M, op, a, b;
    while(scanf("%d %d %d", &N, &Q, &M) != EOF){
        vll v(N, 0LL);
        for(int i = 0; i < N; i++){
            scanf("%d", &b);
            v[i] = 1LL << ((ll)b-1); 
        }
        SegmentTree st(v);
        while(Q--){
            scanf("%d %d %d", &op, &a, &b);
            if(op == 1)
                printf("%d\n", st.query(a-1, b-1));
            else
                st.update(a-1, 1LL << (ll)(b-1));
        }
    }
    return 0;
}
