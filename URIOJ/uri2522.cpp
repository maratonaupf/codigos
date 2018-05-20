/*
 * Leonardo Deliyannis Constantin
 * URI 2522 - Rede do DINF
*/

#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<double, ii> edge;

class UnionFind{
private:
    vector<int> p, rank;
public:
    UnionFind(int N){
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(rank[x] < rank[y])
                p[x] = y;
            else{
                p[y] = x;
                if(rank[x] == rank[y])
                    rank[x]++;
            }
        }
    }
};

struct point{
    int x, y;
    point(){ x = y = 0; } 
    point(int _x, int _y) : x(_x), y(_y) {}
};

double dist(const point &a, const point &b){
    return hypot(b.x - a.x, b.y - a.y);
}

double kruskal(int N, const vector<edge> &els){
    double ret = 0.0;
    UnionFind UF(N);
    for(edge e : els){
        if(!UF.isSameSet(e.second.first, e.second.second)){
            UF.unionSet(e.second.first, e.second.second);
            ret += e.first;
        }
    }
    return ret;
}

int main(){
    int N, x, y, i, j;
    while(scanf("%d", &N) != EOF){
        vector<point> pt;
        vector<edge> els;
        for(i = 0; i < N; i++){
            scanf("%d %d", &x, &y);
            pt.push_back({x, y});
            for(j = 0; j < i; j++){
                els.push_back({dist(pt[j], pt[i]), {j, i}});
            }
        }
        sort(els.begin(), els.end());
        printf("%.2lf\n", kruskal(N, els));
    }
    return 0;
}
