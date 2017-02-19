#include<stdio.h>
#include<string>
#include<map>
#define TAM 512

using namespace std;

int main(void){
	int N, M;
	char id[TAM];
	char s[TAM];
	while(scanf("%d\n", &N) != EOF){
		map<string, string> m;
		while(N--){
			fgets(id, TAM, stdin);
			fgets(s, TAM, stdin);
			m[(string)id] = (string) s;
		}
		scanf("%d\n", &M);
		while(M--){
			fgets(id, TAM, stdin);
			fgets(s, TAM, stdin);
			printf("%s", id);
			printf("%s\n", m[(string)s].c_str());
		}
		m.clear();
	}
	
	return 0;
}
