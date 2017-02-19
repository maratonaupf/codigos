#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

int main(void){
	int N, num, cost;
	while(scanf("%d", &N), N){
		priority_queue<int, vector<int>, greater<int> > pq;
		while(N--){
			scanf("%d", &num);
			pq.push(num);
		}
		cost = 0;
		while(pq.size() > 1){
			num = pq.top();
			pq.pop();
			num += pq.top();
			pq.pop();
			cost += num;
			pq.push(num);
		}
		printf("%d\n", cost);
	}
	return 0;
}
