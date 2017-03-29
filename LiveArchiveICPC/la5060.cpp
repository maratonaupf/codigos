/*
 * Leonardo Deliyannis Constantin
 * ACM ICPC Live Archive 5060 - Arm Wrestling Tournament
 * https://icpcarchive.ecs.baylor.edu/idx.php?option=onlinejudge&page=show_problem&problem=3061
 */

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int K;
struct fighter{
	int idx, maxForce, force;
	vector<int> defeated;
	void rest(){ force = min(force + K, maxForce); }
};

int fight(fighter &winner, fighter &loser){
	if(winner.force < loser.force || (winner.force == loser.force && winner.idx > loser.idx)){
		swap(winner, loser);
	}
	winner.force -= loser.force;
	winner.defeated.push_back(loser.idx);
	winner.rest();
	return winner.idx;
}

int main(){
	int T, N, i;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &K);
		queue<fighter> Q;
		for(i = 1; i <= (1<<N); i++){
			fighter f1;
			scanf("%d", &f1.maxForce);
			f1.force = f1.maxForce;
			f1.idx = i;
			Q.push(f1);
		}
		fighter f1, f2;
		while(!Q.empty()){
			f1 = Q.front(); Q.pop();
			if(Q.empty()) break;
			f2 = Q.front(); Q.pop();
			int win = fight(f1, f2);
			Q.push(f1.idx == win ? f1 : f2);
		}
		printf("%d\n", f1.idx);
		int tam = (int)f1.defeated.size();
		for(i = 0; i < tam; i++){
			printf("%d%c", f1.defeated[i], i < tam-1 ? ' ' : '\n');
		}
	}
	return 0;
}