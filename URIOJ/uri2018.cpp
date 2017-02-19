#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#define MAX 112

using namespace std;

struct pais{
	string nome;
	int medalha[3];
};

bool compare(pais a, pais b){
	for(int i = 0; i < 3; i++){
		if(a.medalha[i] > b.medalha[i])
			return true;
		if(a.medalha[i] < b.medalha[i])
			return false;
	}
	return a.nome < b.nome;
}

map<string, pais> m;
int paises = 0;

void registra(string s, int idx){
	if(m.count(s)){
		m[s].medalha[idx]++;
	}
	else{
		pais aux;
		aux.nome = s;
		memset(aux.medalha, 0, sizeof(aux.medalha));
		m[s] = aux;
		m[s].medalha[idx]++;
		paises++;
	}
}

int main(void){
	char s[MAX];
	string aux;
	
	while(fgets(s, MAX, stdin) != NULL){
		for(int i = 0; i < 3; i++){
			fgets(s, MAX, stdin);
			aux = s; aux[aux.size()-1] = 0;
			registra(aux, i);
		}
	} 
	
	vector<pais> v;
	v.reserve(paises);
	map<string, pais>::iterator it;
	for(it=m.begin(); it!=m.end(); ++it){
		v.push_back(it->second);
	}
	
	sort(v.begin(), v.end(), compare);
	puts("Quadro de Medalhas");
	for(int i = 0; i < paises; i++){
		printf("%s ", v[i].nome.c_str());
		for(int j = 0; j < 3; j++){
			printf("%d%c", v[i].medalha[j], j<2 ? ' ' : '\n');
		}
	}
	
	return 0;
}
