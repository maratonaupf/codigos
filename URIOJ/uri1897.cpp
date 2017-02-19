#include<stdio.h>
#include<map>
#include<queue>
#define INFTO 1123456789

using namespace std;

int op(int N, int i){
	return i == 1 ? N*2 : i == 2 ? N*3 : 
		i == 3 ? N/2 : i == 4 ? N/3 : 
		i == 5 ? N+7 : N-7 ;
}

typedef map<int,int> mib;

int bfs(int s, int t){
	int u, w, i;
	mib dist;
	dist[s] = 0;
	
	queue<int> fila;
	fila.push(s);
	while(!fila.empty()){
		u = fila.front();
		fila.pop();
		if(u == t) break;
		for(i = 1; i <= 6; i++){
			w = op(u, i);
			if(!dist.count(w)){
				dist[w] = dist[u] + 1;
				fila.push(w);
			}
		}
	}
	return dist[t];
}

int main(void){
	int N, M;
	while(scanf("%d %d", &N, &M) != EOF){
		printf("%d\n", bfs(N, M));
	}
	return 0;
}
