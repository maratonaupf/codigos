#include<stdio.h>
#include<stack>
#define MAX 31

using namespace std;

void isPossible(int N, char A[], char B[]){
	int i, j = 0;
	stack<char> s;
	
	for(i = 0; i < N; i++){
		if(s.empty()){
			s.push(A[j++]);
			putchar('I');
		}
		while(s.top() != B[i]){
			if(j == N){
				printf(" Impossible");
				return;
			}
			s.push(A[j++]);
			putchar('I');
		}
		s.pop();
		putchar('R');
	}
}

int main(void){
	int N, i;
	char A[MAX];
	char B[MAX];
	while(scanf("%d", &N), N){
		for(i = 0; i < N; i++){
			scanf(" %c", A+i);
		}
		for(i = 0; i < N; i++){
			scanf(" %c", B+i);
		}
		A[N] = B[N] = '\0';
		isPossible(N, A, B);
		printf("\n");
	}
	return 0;
}
