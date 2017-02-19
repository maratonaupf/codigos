#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 102345

using namespace std;

typedef struct rena{
	char nome[128];
	int peso, idade;
	double altura;
} rena;

bool cmp(rena a, rena b){
	if(a.peso == b.peso){
		if(a.idade == b.idade){
			if(a.altura == b.altura){
				return (strcmp(a.nome, b.nome) < 0);
			}else return (a.altura < b.altura);
		}else return (a.idade < b.idade);
	}else return (a.peso > b.peso);
} 

typedef vector<rena> vr;

int main(){
	vr v;
	rena aux;
	int T, i, cn=0, N, M;
	scanf("%d", &T);
	while(cn++ < T){
		scanf("%d %d", &N, &M);
		for(i=0; i<N; i++){
			scanf("%s %d %d %lf", aux.nome, &aux.peso, &aux.idade, &aux.altura);
			v.push_back(aux);
		}
		sort(v.begin(), v.end(), cmp); 
		printf("CENARIO {%d}\n", cn);
		for(i=0; i<M; i++)
			printf("%d - %s\n", i+1, v[i].nome);
		v.clear();
	}
	return 0;
}
