#include<stdio.h>
#include<algorithm>
using namespace std;

inline int solve(int a, int b, int c){
	if(a > b && a > c) return b*2 + c*4;
	if(c > a && c > b) return a*4 + b*2;
	return a*2 + c*2;
}

inline int min(int a, int b, int c){
	return min(a, min(b, c));
}

int main(){
	int a, b, c, x, y, z;
	while(scanf("%d %d %d", &a, &b, &c) != EOF){
		x = b*2 + c*4;
		y = a*2 + c*2;
		z = a*4 + b*2;
		printf("%d\n", min(x, y, z));
	}
	return 0;
}
