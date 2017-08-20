#include<iostream>
#include<stdio.h>
using namespace std;
#define NIL (-112345678)

// to-do: implementar árvore binária NÃO-balanceada

struct nodo{
	nodo *pai;
	int valor;
	nodo *f[2];
	nodo(){
		valor = NIL;
		pai = f[0] = f[1] = nullptr;
	}
	nodo(int val, nodo* _pai){
		valor = val;
		pai = _pai;
	}
};

struct arvore{
	nodo *raiz;
	arvore(){ 
		raiz = nullptr;
	}
	void insert(int x, nodo *pai){
		if(*pai == nullptr) atual =
	}
	void insert(int x){
		if(raiz == nullptr) *raiz = new nodo(x, nullptr);
		else{
			if(x < raiz->value){
				
			}
		}
	}
	bool search(){
		
	}
	void remove(){
		
	}
	void prefix(){
		
	}
	void infix(){
		
	}
	void postfix(){
		
	}
	void clear(){
		
	}
};

int main(){
	char str[10];
	string op;
	int x;
	arvore t;
	while(scanf("%s ", str) != EOF){
		op = str;
		switch(op){
			case "I": 
				scanf("%d", &x);
				t.insert(x);
				break;
			case "P": 
				scanf("%d", &x);
				printf("%d %sexiste\n", x, t.search(x) ? "" : "nao ");
				break;
			case "R": 
				scanf("%d", &x);
				t.remove(x);
				break;
			case "INFIXA": 
				t.infix();
				break;
			case "POSFIXA":
				t.postfix();
				break;
			case "PREFIXA": 
				t.prefix();
				break;
		}
		t.clear();
	}
	return 0;
}
