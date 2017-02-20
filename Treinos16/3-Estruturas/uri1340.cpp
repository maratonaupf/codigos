#include<stdio.h>
#include<stack>
#include<queue>

using namespace std;

int main(void){
	int N;
	int op, x, i;
	bool naJogada[3];
	while(scanf("%d", &N) != EOF){
		stack<int> s;
		queue<int> q;
		priority_queue<int> h;
		int validas = 0;
		
		for(i = 0; i < 3; i++) naJogada[i] = true;
		while(N--){
			scanf("%d %d", &op, &x);
			if(op == 1){
				if(naJogada[0]) s.push(x);
				if(naJogada[1]) q.push(x);
				if(naJogada[2]) h.push(x);	
			}
			else if(op == 2){
				if(naJogada[0]){
					if(s.top() == x) s.pop();
					else naJogada[0] = false;
				}
				if(naJogada[1]){
					if(q.front() == x) q.pop();
					else naJogada[1] = false;
				}
				if(naJogada[2]){
					if(h.top() == x) h.pop();
					else naJogada[2] = false;
				}
			}
		}
		for(i = 0; i < 3; i++){
			if(naJogada[i]) validas++;
		}
		printf("%s\n", validas > 1 ? "not sure" : validas == 0 ? "impossible" : 
			naJogada[0] ? "stack" : naJogada[1] ? "queue" : "priority queue");
		// while(!s.empty()) s.pop();
		// while(!q.empty()) q.pop();
		// while(!h.empty()) h.pop();
	}
	return 0;
}
