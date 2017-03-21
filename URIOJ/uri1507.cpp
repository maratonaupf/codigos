#include<stdio.h>
#include<string.h>
#define MAX 112345
//#define DEBP

int ls[256][MAX];
int tam[256];

void prep(char *s){
	int i;
	memset(tam, 0, sizeof(tam));
	for(i = 0; s[i]; i++){
		int a = s[i];
		ls[a][tam[a]++] = i;
	}
}

int pos[MAX];
int oc[256];
int topo;

bool subseq(char *s, char *r){
	memset(oc, 0, sizeof(oc));
	int i; topo = -1;
	for(i = 0; r[i]; i++){
		int a = r[i];
		if(!tam[a]) return false;
		if(topo >= 0){
			while(ls[a][oc[a]] < pos[topo] && oc[a] < tam[a]) oc[a]++;
			if(oc[a] == tam[a]) return false;
			pos[++topo] = ls[a][oc[a]++];
		} 
		else pos[++topo] = ls[a][oc[a]++];
	}
	return true;
}

int main(void){
	int N, Q;
	char s[MAX], r[112];
	scanf("%d", &N);
	getchar();
	while(N--){
		scanf("%s", s);
		scanf("%d", &Q);
		getchar();
		prep(s);
		while(Q--){
			scanf("%s", r);
			puts(subseq(s, r) ? "Yes" : "No");
		}
	}
	return 0;
}
