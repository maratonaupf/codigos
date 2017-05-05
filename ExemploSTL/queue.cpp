#include <stdio.h>
#include <queue>
using namespace std;

int main(){
	queue<int> fila;
	int N, i, x;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &x);
		fila.push(x);
	}
	while(!fila.empty()){
		printf("Frente: %d\n", fila.front());
		fila.pop();
	}
	return 0;
}