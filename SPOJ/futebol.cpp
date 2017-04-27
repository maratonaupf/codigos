/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/FUTEBOL/
 */

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cctype>
using namespace std;
#define LEN 17

struct team{
	string name;
	int pts, gp, gf, ga;
	team(){
		name = "";
		pts = gp = gf = ga = 0;
	}
	int gd(){ return gf - ga; }
};

bool tied(team a, team b){
	return a.pts == b.pts 
		&& a.gd() == b.gd()
		&& a.gf  == b.gf;
}

string toLowerCase(const string &s){
	string t = s;
	int i, sz = s.size();
	for(i = 0; i < sz; i++){
		t[i] = tolower(t[i]);
	}
	return t;
}

bool cmp(team a, team b){
	if(a.pts != b.pts) return a.pts > b.pts;
	if(a.gd() != b.gd()) return a.gd() > b.gd();
	if(a.gf != b.gf) return a.gf > b.gf;
	return toLowerCase(a.name) < toLowerCase(b.name);
}

int makePoints(const int &self, const int &other){
	return (self > other) ? 3 : (self == other) ? 1 : 0;
}

map<string, int> idx;
vector<team> v;
int totalPoints;

void computeGameForTeam(const string &myTeam, const int &g1, const int &g2){
	int id = idx[myTeam], points = makePoints(g1, g2);
	totalPoints += points;
	v[id].pts += points;
	v[id].gp++;
	v[id].gf += g1;
	v[id].ga += g2;
}

int main(){
	int T, G, i;
	int g1, g2;
	char s1[LEN], s2[LEN];
	bool first = true;
	while(scanf("%d %d\n", &T, &G), T != 0){
		first ? first = false : printf("\n");
		v.assign(T, team());
		totalPoints = 0;
		for(i = 0; i < T; i++){
			scanf("%s\n", s1);
			v[i].name = s1;
			idx[s1] = i;
		}
		for(i = 0; i < G; i++){
			scanf("%s %d - %d %s\n", s1, &g1, &g2, s2);
			computeGameForTeam(s1, g1, g2);
			computeGameForTeam(s2, g2, g1);
		}
		idx.clear();
		sort(v.begin(), v.end(), cmp);
		for(i = 0; i < T; i++){
			if(i > 0 && tied(v[i-1], v[i])){ printf("   "); }
			else{ printf("%2d.", i+1); }
			printf(" %15s", v[i].name.c_str());
			printf(" %3d %3d %3d %3d %3d", 
				v[i].pts, v[i].gp, v[i].gf, v[i].ga, v[i].gd());
			if(v[i].gp > 0){
				printf(" %6.2lf\n", (double)v[i].pts*100.0 / (double) (v[i].gp * 3));
			}
			else{ printf("    N/A\n"); }
		}
		v.clear();
	}
	return 0;
}
