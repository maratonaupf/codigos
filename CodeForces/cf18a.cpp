/*
 * Leonardo Deliyannis Constantin
 * http://codeforces.com/problemset/problem/18/A
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define x first
#define y second
#define ALL(_myvec) (_myvec.begin()), (_myvec.end())
#define NP next_permutation

typedef pair<int, int> point;
typedef point vec;
typedef vector<point> vp;

vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}

int prod(vec a, vec b){
    return a.x*b.x + a.y*b.y;
}

bool isRight(vp &v){
    sort(ALL(v));
    if(v[0] == v[1] || v[1] == v[2]) return false;
    vec xy = toVec(v[0], v[1]);
    vec xz = toVec(v[0], v[2]);
    vec yz = toVec(v[1], v[2]);
    return prod(xy, xz) == 0 || prod(xy, yz) == 0 || prod(xz, yz) == 0;
}

bool modifyAndTest(vp v, int idx, int isX, int plus){
    if(isX) v[idx].x += (plus ? 1 : -1);
    else    v[idx].y += (plus ? 1 : -1);
    return isRight(v);
}

bool almostRight(vp &v){
    int i, j, k;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 2; j++)
            for(k = 0; k < 2; k++)
                if(modifyAndTest(v, i, j, k)) return true;
    return false;
}

string verdict(vp &v){
    if(isRight(v)) return "RIGHT";
    if(almostRight(v)) return "ALMOST";
    return "NEITHER";
}

int main(){
    vp v(3);
    while(scanf("%d %d", &v[0].x, &v[0].y) != EOF){
        scanf("%d %d", &v[1].x, &v[1].y);
        scanf("%d %d", &v[2].x, &v[2].y);
        printf("%s\n", verdict(v).c_str());
    }
    return 0;
}
