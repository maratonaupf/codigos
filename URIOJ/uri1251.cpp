#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256

struct letter{
	int c;
	int freq;
};

int cmp(const void *la, const void *lb){
	letter a = *(letter*)la;
	letter b = *(letter*)lb;
	return (a.freq == b.freq) ? 
		b.c - a.c :
		a.freq - b.freq;
}

int main(void){
	int c;
	int count[MAX];
	letter v[MAX];
	bool first = true;
	int tam = 0;
	memset(count, 0, sizeof(count));
	while((c = getchar()) != EOF){
		if(c != '\n'){
			count[c]++;
		}
		else{
			for(int i = 0; i < MAX; i++){
				if(count[i]){
					v[tam].c = i;
					v[tam++].freq = count[i]; 
				}
			}
			qsort(v, tam, sizeof(letter), cmp);
			if(first) first = false;
			else printf("\n");
			for(int i = 0; i < tam; i++){
				printf("%d %d\n", v[i].c, v[i].freq);
			}
			memset(count, 0, sizeof(count));
			tam = 0;
		}
	}
	return 0;
}
