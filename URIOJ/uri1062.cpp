#include<stdio.h>
#include<stack>
#define MAX 1123

using namespace std;

bool isPossible(int N, int B[]){
	int A = 1, i;
	stack<int> s;
	
	for(i = 0; i < N; i++){
		if(s.empty()){
			s.push(A++);
		}
		while(s.top() != B[i]){
			if(A > N){
				return false;
			}
			s.push(A++);
		}
		s.pop();
	}
	return true;
}

int main(void){
	int N, i;
	int v[MAX];
	while(scanf("%d", &N), N){
		while(scanf("%d", v), v[0]){
			for(i = 1; i < N; i++){
				scanf("%d", v+i);
			}
			
			puts(isPossible(N, v) ? "Yes" : "No");
		}
		printf("\n");
	}
	return 0;
}
