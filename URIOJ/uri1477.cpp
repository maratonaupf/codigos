/*
 * Leonardo Deliyannis Constantin
 * URI 1477 - Homem, Elefante e Rato
*/

#include <stdio.h>
#include <vector>
using namespace std;

typedef vector<int> vi;

struct count{
    vi cnt;
    count(){ cnt.assign(3, 0); }
    void shift(int n){
        n %= 3;
        vi tmp = cnt;
        for(int i = 0; i < 3; i++)
            cnt[i] = tmp[(i - n + 3) % 3];
    }
    count operator +(const count &other) const{
        count res;
        for(int i = 0; i < 3; i++)
            res.cnt[i] = cnt[i] + other.cnt[i];
        return res;
    }
};

class SegmentTree{
private:
    vector<count> st;
    vi lazy;
    int size;
#define left(p)  ((p << 1) | 1)
#define right(p) ((p << 1) + 2)
    void build(int p, int l, int r){
        if(l == r)
            st[p].cnt[0] = 1;
        else{
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2+1, r);
            st[p] = st[left(p)] + st[right(p)];
        }
    }
    void push(int p, int l, int r){
        st[p].shift(lazy[p]);
        if(l != r){
            lazy[left(p)] += lazy[p];
            lazy[right(p)] += lazy[p];
        }
        lazy[p] = 0;
    }
    count query(int p, int l, int r, int a, int b){
        push(p, l, r);
        if(a > r || b < l) return count();
        if(l >= a && r <= b) return st[p];
        return query(left(p), l, (l+r)/2, a, b) +
            query(right(p), (l+r)/2+1, r, a, b);
    }
    void update(int p, int l, int r, int a, int b, int v){
        push(p, l, r);
        if(a > r || b < l) return;
        if(l >= a && r <= b){
            lazy[p] += v;
            push(p, l, r);
        }else{
            update(left(p), l, (l+r)/2, a, b, v);
            update(right(p), (l+r)/2+1, r, a, b, v);
            st[p] = st[left(p)] + st[right(p)];
        }
    }
public:
    SegmentTree(int N){
        size = N;
        st.assign(4*size, count());
        lazy.assign(4*size, 0);
        build(0, 0, size-1);
    }
    count query(int a, int b){
        return query(0, 0, size-1, a, b); }
    void update(int a, int b, int v){
        update(0, 0, size-1, a, b, v);
    }
};

int main(){
    int N, M, a, b;
    char c;
    while(scanf("%d %d", &N, &M) != EOF){
        SegmentTree st(N);
        while(M--){
            scanf(" %c %d %d", &c, &a, &b);
            a--, b--;
            if(c == 'C'){
                count ans = st.query(a, b);
                for(int i = 0; i < 3; i++){
                    printf("%d%c", ans.cnt[i], i < 2 ? ' ' : '\n');
                }
            }
            else
                st.update(a, b, 1);
        }
        printf("\n");
    }
    return 0;
}
