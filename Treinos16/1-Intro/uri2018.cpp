//#include<stdio.h>
#include<iostream>
//#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
//#define MAX 112

using namespace std;

struct pais{
	string nome;
	int medalha[3];
};

typedef map<string, pais> msp;

bool compare(pais a, pais b){
	for(int i = 0; i < 3; i++){
		if(a.medalha[i] > b.medalha[i]){
			return true;
		}
		if(a.medalha[i] < b.medalha[i]){
			return false;
		}
	}
	return a.nome < b.nome;
}

msp m;
int paises = 0;

void registra(string s, int idx){
	if(m.count(s)){
		m[s].medalha[idx]++;
	}
	else{
		pais aux;
		aux.nome = s;
		//memset(aux.medalha, 0, sizeof(aux.medalha));
		for(int i = 0; i < 3; i++){
			aux.medalha[i] = 0;
		}
		m[s] = aux;
		m[s].medalha[idx]++;
		paises++;
	}
}

int main(void){
	//char s[MAX];
	string s;
	//string aux;
	
	//while(fgets(s, MAX, stdin) != NULL){
	while(getline(cin, s)){
		for(int i = 0; i < 3; i++){
			//fgets(s, MAX, stdin);
			getline(cin, s);
			//aux = s; 
			//aux[aux.size()-1] = 0;
			registra(s, i);
		}
	} 
	
	vector<pais> v;
	v.reserve(paises);
	msp::iterator it;
	
	for(it=m.begin(); it!=m.end(); it++){
		v.push_back(it->second);
	}
	
	sort(v.begin(), v.end(), compare);
	//puts("Quadro de Medalhas");
	cout << "Quadro de Medalhas" << endl;
	for(int i = 0; i < paises; i++){
		//printf("%s", v[i].nome.c_str());
		cout << v[i].nome;
		for(int j = 0; j < 3; j++){
			//printf(" %d", v[i].medalha[j]);
			cout << " " << v[i].medalha[j];
		}
		//printf("\n");
		cout << endl;
	}
	
	return 0;
}
