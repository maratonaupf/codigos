#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define LEN 212

int main(){
	int N, i, j, cnt, tam;
	char s[LEN];
	while(scanf("%d\n", &N) != EOF){
		vector<string> v;
		tam = -1;
		for(i = 0; i < N; i++){
			fgets(s, LEN, stdin);
			if(tam == -1) tam = strlen(s) - 1;
			s[tam] = 0;
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		cnt = 0;
		for(i = 1; i < N; i++){
			for(j = 0; j < tam; j++){
				if(v[i-1][j] == v[i][j]) cnt++;
				else break;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
