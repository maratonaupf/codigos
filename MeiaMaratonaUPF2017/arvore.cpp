#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <algorithm>

#define eq(a,b) (strcmp(a,b)==0)

using namespace std;
struct nodo {
	nodo *p;
	int k;
	nodo *l, *r;
};

nodo* minimum(nodo* T){ return (T->l ? minimum(T->l) : T); }
nodo* maximum(nodo* T){ return (T->r ? maximum(T->r) : T); }

nodo* search(nodo* T, int v){
	if(T == nullptr || v == T->k) return T;
	if(v < T->k) return search(T->l, v);
	if(v > T->k) return search(T->r, v);
	return nullptr;
}

nodo* aloca(int v) {
	nodo *N = new nodo;
	N->p = nullptr; 
	N->k = v;
	N->l = N->r = nullptr;
	return N;
}

nodo * insere (nodo * T, int v) {
    if(T){
        if (T->k > v) {
            if(T->l) insere(T->l, v);
            else{
                T->l = aloca(v);
                T->l->p = T;
            }
        } else if (T->k < v) {
            if(T->r) insere(T->r, v);
            else{
                T->r = aloca(v);
                T->r->p = T;
            }
        }
    }
    else T = aloca(v);
    return T;
}

void prefixo(nodo *T) {
	if(T){
		printf("%d", T->k);
		if(T->l){ printf(" "); prefixo(T->l); }
		if(T->r){ printf(" "); prefixo(T->r); }
	}
}
  
void infixo(nodo *T) {
	if(T){
		if(T->l){ infixo(T->l); printf(" "); }
		printf("%d", T->k);
		if(T->r){ printf(" "); infixo(T->r); }
	}
}
  
void posfixo(nodo *T) {
	if(T){
		if(T->l){ posfixo(T->l); printf(" "); }
		if(T->r){ posfixo(T->r); printf(" "); }
		printf("%d", T->k);
	}
}

nodo* retira(nodo* T, int v) {
	if(T == nullptr) return T;
	else if(v < T->k) T->l = retira(T->l, v);
	else if(v > T->k) T->r = retira(T->r, v);
	else{
		if(!(T->l || T->r)){ // no child
			delete T;
			T = nullptr;
		}
		else if(!(T->l && T->r)){ // one child
			nodo* aux = T;
			T = (T->l) ? T->l : T->r;
			delete aux;
		}
		else{
			nodo* aux = maximum(T->l);
			T->k = aux->k;
			T->l = retira(T->l, aux->k);
		}
	}
	return T;
}


int main(void){
	nodo* T = nullptr;
	int v;
	char op[8];
	while(scanf("%s", op)!=EOF){	
		if(eq(op,"I")){
			scanf("%d", &v);
			T = insere(T, v);
		}else
		
		if(eq(op,"INFIXA")) { infixo(T); printf("\n"); }else
		if(eq(op,"PREFIXA")){ prefixo(T); printf("\n"); }else
		if(eq(op,"POSFIXA")){ posfixo(T); printf("\n"); }else
		
		if(eq(op,"P")){
			scanf("%d", &v);
			printf("%d%s existe\n", v, search(T, v) ? "" : " nao");
		}else
		
		if(eq(op,"R")){
			scanf("%d", &v);
			T = retira(T, v);
		}
	}
	return 0;
}
