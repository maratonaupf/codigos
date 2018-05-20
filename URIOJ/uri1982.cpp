/*
 * Leonardo Deliyannis Constantin
 * URI 1982 - Novos Computadores
*/

#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define EPS 1e-9

struct point{
    int x, y;
    point(){ x = y = 0.0; }
    point(int _x, int _y): x(_x), y(_y) {}
    bool operator <(const point &other) const{
        return (x != other.x) ? x < other.x : y < other.y;
    }
    bool operator ==(const point &other) const{
        return x == other.x && y == other.y;
    }
    bool operator !=(const point & other) const{
        return x != other.x || y != other.y;
    }
};

struct vec{
    double x, y;
    vec(double _x, double _y): x(_x), y(_y) {}
    vec(const point &a, const point &b){
        x = b.x - a.x, y = b.y - a.y;
    }
};

double dist(const point &a, const point &b){
    return hypot(b.x-a.x, b.y-a.y);
}

double cross(const vec &a, const vec &b){
    return a.x * b.y - a.y * b.x;
}

bool ccw(const point &p, const point &q, const point &r){
    return cross(vec(p, q), vec(p, r)) > 0;
}

bool collinear(const point &p, const point &q, const point &r){
    return fabs(cross(vec(p, q), vec(p, r))) < EPS;
}

point pivot;
bool angleCmp(const point &a, const point &b){
    if(collinear(pivot, a, b))
        return dist(pivot, a) < dist(pivot, b);
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> ch(vector<point> P){
    int i, j, n = (int)P.size();
    if(n <= 3){
        if(P[0] != P[n-1]) P.push_back(P[0]);
        return P;
    }
    int P0 = 0;
    for(i = 1; i < n; i++)
        if(P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
    
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    
    vector<point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
    i = 2;
    while(i < n){
        j = (int)S.size()-1;
        if(ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
        else S.pop_back();
    }
    return S;
}

int main(){
    int N, i, x, y;
    double ans;
    vector<point> v, P;
    while(scanf("%d", &N), N != 0){
        v.assign(N, {0, 0});
        while(N--){
            scanf("%d %d", &x, &y);
            v[N] = {x, y};
        }
        P = ch(v);
        ans = 0.0;
        for(i = 1; i < (int)P.size(); i++){
            ans += dist(P[i-1], P[i]);
        }
        printf("Tera que comprar uma fita de tamanho %.2lf.\n", ans);
    }
    return 0;
}
