#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;

int main(){
	int N, op, x;
	bool pilha, fila, heap;
	while(scanf("%d", &N) != EOF){
		fila = pilha = heap = true;
		stack<int> S;
		queue<int> Q;
		priority_queue<int> H;
		while(N--){
			scanf("%d %d", &op, &x);
			if(op == 1){
				if(pilha) S.push(x);
				if(fila) Q.push(x);
				if(heap) H.push(x);
			}
			else{
				if(S.empty() || S.top() != x) pilha = false;
				else S.pop();
				if(Q.empty() || Q.front() != x) fila = false;
				else Q.pop();
				if(H.empty() || H.top() != x) heap = false;
				else H.pop();
			}
		}
		if(pilha && !fila && !heap) printf("stack");
		else if(!pilha && fila && !heap) printf("queue");
		else if(!pilha && !fila && heap) printf("priority queue");
		else if(!pilha && !fila && !heap) printf("impossible");
		else printf("not sure");
		printf("\n");
	}
	return 0;
}
