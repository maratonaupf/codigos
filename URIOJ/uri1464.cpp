/*
 * Leonardo Deliyannis Constantin
 * URI 1464 - Camadas de Cebola
 */

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define pb push_back

struct point{
	int x, y;
	point(){ x = y = 0; }
	point(int _x, int _y) : x(_x), y(_y) {}
	bool operator <(const point &other) const{
		return x < other.x || (x == other.x && y < other.y);
	}
};

// take collinear points into consideration by returning 
bool ccw(const point &a, const point &b, const point &c) {
    return a.x * (b.y - c.y)
         + b.x * (c.y - a.y)
         + c.x * (a.y - b.y) >= 0; // instead of > 0
}

// same as above
bool cw(const point &a, const point &b, const point &c) {
    return a.x * (b.y - c.y)
         + b.x * (c.y - a.y)
         + c.x * (a.y - b.y) <= 0; // instead of < 0
}

bool convexHull(set <point> &s) {
    vector <point> up, down;
    if(s.size() < 1) return false;
    auto it = s.begin();
    up.pb(*it);
    down.pb(*it);
    for(++it; it != s.end(); ++it) {
        while(up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], *it)) {
            up.pop_back(); 
        }
        while(down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], *it)) {
            down.pop_back();
        }
        up.pb(*it);
        down.pb(*it);
    }
    for(int i = down.size() - 2; i > 0; i--) {
        up.pb(down[i]);
    }
    if(up.size() < 3) return false;
    for(int i = 0; i < (int)up.size(); i++){
        s.erase(up[i]);
    }
    return true;
}

int main(){
	int N, i, px, py, layers;
	while(scanf("%d", &N), N != 0){
		set<point> s;
		for(i = 0; i < N; i++){
			scanf("%d %d", &px, &py);
			s.insert(point(px, py));
		}
		layers = 0;
		while(convexHull(s)){
			layers++;
		}
		printf("%s this onion to the lab!\n", (layers&1) 
			? "Take" : "Do not take");
	}
	return 0;
}
