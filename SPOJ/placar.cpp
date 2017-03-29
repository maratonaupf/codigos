/*
 * Leonardo Deliyannis Constantin
 * http://br.spoj.com/problems/PLACAR/
 */

#include <stdio.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define LEN 22

struct aluno{
	string name;
	int score;
};

bool cmp(aluno a, aluno b){
	if(a.score == b.score){
		return a.name < b.name;
	}
	return a.score > b.score;
}

int main(){
	int N, test = 0;
	char s[LEN];
	while(scanf("%d\n", &N) != EOF){
		vector<aluno> v(N);
		for(int i = 0; i < N; i++){
			scanf("%s %d\n", s, &v[i].score);
			v[i].name = s;
		}
		sort(v.begin(), v.end(), cmp);
		printf("Instancia %d\n", ++test);
		printf("%s\n", v[N-1].name.c_str());
	}
	return 0;
}