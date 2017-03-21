#include<stdio.h>
#define MAX 112345

using namespace std;

int main(void){
	int N, D;
	int c, top;
	char s[MAX];
	while(scanf("%d %d\n", &N, &D), N){
		top = -1;
		for(int i = 0; i < N; i++){
			c = getchar();
			while(top >= 0 && s[top] < c && D > 0){
				top--;
				D--;
			}
			s[++top] = c;
		}
		while(top >= 0 && D > 0){
			top--;
			D--;
		}
		s[top+1] = 0;
		puts(s);
	}
	return 0;
}
