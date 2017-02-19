#include<stdio.h>
#include<queue> // priority_queue<>
#include<utility> // make_pair()
#include<algorithm> // max()
#define MAX 11234

using namespace std;

typedef pair<int,int> ii;

int main(void){
	int N, M;
	int v[MAX];
	int resp, cli, func, livre, tempo;
	priority_queue<ii> fila;
	while(scanf("%d %d", &N, &M) != EOF){
		while(!fila.empty()) fila.pop();
		for(int i = 1; i <= N; i++){
			scanf("%d", v+i);
			fila.push(make_pair(0, -i));
		}
		resp = 0;
		while(M--){
			scanf("%d", &cli);
			func = -fila.top().second;
			livre = -fila.top().first;
			fila.pop();
			
			tempo = livre+v[func]*cli;
			fila.push(make_pair(-tempo, -func));
			resp = max(resp, tempo);
		}
		printf("%d\n", resp);
	}
	return 0;
}
