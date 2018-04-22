/*
 * Leonardo Deliyannis Constantin
 * CodeForces 522A - Reposts
 */

#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
#define LEN 32
#define INFTO ((int)1e9)

// REMINDER: NAMES ARE ***CASE-INSENSITIVE!!!***

map<string, vector<string> > LG;
map<string, int> dist;

string lower(char *s){
	for(int i = 0; s[i]; i++){
		s[i] = tolower(s[i]);
	}
	return string(s);
}

int bfs(string s){
	for(auto it = LG.begin(); it != LG.end(); ++it){
		dist[it->first] = INFTO;
	}
	dist[s] = 1;
	queue<string> Q;
	Q.push(s);
	while(!Q.empty()){
		string u = Q.front(); Q.pop();
		for(int i = 0; i < (int)LG[u].size(); i++){
			string v = LG[u][i];
			if(dist[v] > dist[u] + 1){
				dist[v] = dist[u] + 1;
				Q.push(v);
			}
		}
	}
	int ans = 0;
	for(auto it = LG.begin(); it != LG.end(); ++it){
		if(dist[it->first] != INFTO)
			ans = max(ans, dist[it->first]);
	}
	return ans;
}

int main(){
	int E, i;
	char a[LEN], b[LEN];
	while(scanf("%d", &E) != EOF){
		LG.clear();
		for(i = 0; i < E; i++){
			scanf("%s %*s %s", b, a);
			LG[lower(a)].push_back(lower(b));
			if(!LG.count(b)) LG[b].clear();
		}
		printf("%d\n", bfs("polycarp"));
	}
	return 0;
}
