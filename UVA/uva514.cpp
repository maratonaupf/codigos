#include<stdio.h>
#include<stack>
#define MAX 1123
using namespace std;
#define DEBP

bool simulation(int a[], int N){
	int i = 0, w = 1;
	stack<int> s;
	while(i < N){
		while(s.empty() || s.top() != a[i]){
			if(w <= N) s.push(w++);
			else return false;
		}
		s.pop();
		i++;
	}
	return true;
}

int main(void){
	int N, i;
	int a[MAX];
	while(scanf("%d", &N), N != 0){
		while(scanf("%d", a), a[0] != 0){
			for(i = 1; i < N; i++){
				scanf("%d", a+i);
			}
			printf("%s\n", simulation(a, N) ? "Yes" : "No");
		}
		printf("\n");
	}
	return 0;
}
