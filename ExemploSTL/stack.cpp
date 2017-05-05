#include <stdio.h>
#include <stack>
using namespace std;

int main(){
	stack<int> pilha;
	int N, i, x;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &x);
		pilha.push(x);
	}
	while(!pilha.empty()){
		printf("Topo: %d\n", pilha.top());
		pilha.pop();
	}
	return 0;
}