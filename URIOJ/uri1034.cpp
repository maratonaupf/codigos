#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define INFTO ((1<<30) -1)

typedef vector<int> vi;

int N, M;
int c[112];

int PD(){
	vi pd(M+1, INFTO);
	pd[0] = 0;
	for(int i = 1; i <= M; i++){
		for(int j = 1; j <= N; j++){
			if(0 <= i - c[j]) pd[i] = min(pd[i], pd[i-c[j]] + 1);
		}
	}
	return pd[M];
}

int main(void){
	int T, i;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &M);
		for(i = 1; i <= N; i++) scanf("%d", c+i);
		printf("%d\n", PD());
	}
	return 0;
}
