#include<stdio.h>
#include<algorithm>
using namespace std;

inline int solve(int a, int b, int c){
	if(a >= b && a >= c) return b*2 + c*4;
	if(c >= a && c >= b) return a*4 + b*2;
	return a*2 + c*2;
}

int main(){
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) != EOF){
		printf("%d\n", solve(a, b, c));
	}
	return 0;
}
