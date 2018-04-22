/*
 * Leonardo Deliyannis Constantin
 * CodeForces 727 A - Transformation: from A to B
*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
vi path;

bool bfs(ll s, ll t){
	ll u, v;
	path.clear();
	map<ll, ll> p;
	map<ll, bool> vis;
	p[s] = s;
	vis[s] = true;
	priority_queue<ll, vector<ll>, greater<ll> > Q;
	Q.push(s);
	while(!Q.empty()){
		u = Q.top(); Q.pop();
		if(u >= t) break;
		for(int i = 0; i < 2; i++){
			v = (i == 0) ? (2LL * u) : (10LL * u + 1LL);
			if(!vis[v]){
				vis[v] = true;
				p[v] = u;
				Q.push(v);
			}
		}
	}
	if(!vis[t]) return false;
	for(u = t; u != s; u = p[u]){
		path.push_back((int)u);
	}
	path.push_back((int)s);
	return true;
}

int main(){
	int a, b, i;
	while(scanf("%d %d", &a, &b) != EOF){
		if(bfs(a, b) == false){
			printf("NO\n");
		}
		else{
			printf("YES\n");
			i = (int)path.size();
			printf("%d\n", i);
			for(i = i-1; i >= 0; i--){
				printf("%d ", path[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
