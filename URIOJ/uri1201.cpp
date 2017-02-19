#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cassert>

#include<sys/time.h>
#include<algorithm>

#define eq(a,b) (strcmp(a,b)==0)

//#define GUI

using namespace std;

typedef struct nodo {
	nodo* p;
	 int k;
nodo* l; nodo* r;
} nodo;

nodo* minimum(nodo* T){ return (T->l ? minimum(T->l) : T); }
nodo* maximum(nodo* T){ return (T->r ? maximum(T->r) : T); }

nodo* search(nodo* T, int v){
	if(T == NULL || v == T->k) return T;
	if(v < T->k) return search(T->l, v);
	if(v > T->k) return search(T->r, v);
	return NULL;
}

nodo* aloca(int v) {
	nodo *N = (nodo *) malloc(sizeof(nodo));
	N->p = NULL; 
	N->k = v;
	N->l = N->r = NULL;
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
	if(T == NULL) return T;
	else if(v < T->k) T->l = retira(T->l, v);
	else if(v > T->k) T->r = retira(T->r, v);
	else{
		if(!(T->l || T->r)){ // no child
			free(T);
			T = NULL;
		}
		else if(!(T->l && T->r)){ // one child
			nodo* aux = T;
			T = (T->l) ? T->l : T->r;
			free(aux); 
		}
		else{
			nodo* aux = maximum(T->l);
			T->k = aux->k;
			T->l = retira(T->l, aux->k);
		}
	}
	return T;
}

// FUNÇÕES DE INTERAÇÃO COM O USUÁRIO
#ifdef GUI

void strcaps(const char *s){
	int i;
	for(i=0; s[i]; i++)
		s[i] = toupper(s[i]);
}

void espere() {  
    printf("Press enter to continue...\n");
    getchar();
    getchar();
}

void menu( ) {
	system("clear");
	puts("I x - insere nodo de valor X\n"
		 "")
	return;
}
#endif
// FIM DAS FUNÇÕES DE INTERAÇÃO COM O USUÁRIO

int main(void){
	nodo* T = NULL;
	int v;
	char op[8];
	while(scanf("%s", op)!=EOF){
#ifdef GUI
		strcaps(op);
#endif		
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
