/*
 * Leonardo Deliyannis Constantin
 * Argus
 */

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int, int> ii;
map<int, int> t;
map<int, int> att;

int main(){
	char s[11];
	int q, p, K;
	vector<int> v;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	while(scanf(" %s", s), s[0] != '#'){
		scanf("%d %d", &q, &p);
		v.push_back(q);
		t[q] = p;
		pq.push(ii(p, q));
	}
	sort(v.begin(), v.end());
	scanf(" %d", &K);
	while(K--){
		q = pq.top().second;
		p = pq.top().first;
		pq.pop();
		att[q]++;
		pq.push(ii(p+t[q], q));
	}
	for(int i = 0; i < (int)v.size(); i++){
		printf("Register %d = %d\n", v[i], att[v[i]]);
	}
	return 0;
}
