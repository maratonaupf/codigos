/*
 * Leonardo Deliyannis Constantin
 * http://www.codcad.com/problem/48
 */

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct consulta{
	int ini, fim;
	consulta(){ ini = fim = 0; }
};


bool comp(consulta a, consulta b){
	return a.fim < b.fim;
}

int main(){
	int N, i, livre, atend;
	while(scanf("%d", &N) != EOF){
		vector<consulta> v(N, consulta());
		for(i = 0; i < N; i++){
			scanf("%d %d", &v[i].ini, &v[i].fim);
		}
		sort(v.begin(), v.end(), comp);
		atend = livre = 0;
		for(i = 0; i < N; i++){
			if(livre <= v[i].ini){
				atend++;
				livre = v[i].fim;
			}
		}
		printf("%d\n", atend);
	}
	return 0;
}
