#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;

int main(void){
	int N, op, x;
	int i, count;
	bool valid[3];
	while(scanf("%d", &N) != EOF){
		stack<int> s;
		queue<int> q;
		priority_queue<int> h;
		for(i = 0; i < 3; i++) valid[i] = true;
		while(N--){
			scanf("%d %d", &op, &x);
			if(op == 1){
				s.push(x);
				q.push(x);
				h.push(x);
			}
			if(op == 2){
				if(valid[0]){
					if(!s.empty() && s.top() == x) s.pop();
					else valid[0] = false;
				}
				if(valid[1]){
					if(!q.empty() && q.front() == x) q.pop();
					else valid[1] = false;
				}
				if(valid[2]){
					if(!h.empty() && h.top() == x) h.pop();
					else valid[2] = false;
				}
			}
		}
		count = 0;
		for(i = 0; i < 3; i++) if(valid[i]) count++;
		printf("%s\n", count > 1 ? "not sure" : valid[0] ? "stack" :
			valid[1] ? "queue" : valid[2] ? "priority queue" : "impossible");
	}
	return 0;
}
