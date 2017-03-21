#include<stdio.h>
#include<string.h>
#define MAX 5003
#define DEBP

char s[MAX];
char al[] = "NOP";
size_t tam;

bool isValid(){
	size_t i, j, pa, pb;
	bool blz;
	for(i = 1; i <= tam >> 1; i++){
		pa = tam-(i<<1);
		pb = tam-i;
		blz = false;
		for(j = 0; j < i; j++){
			if(s[pa+j] != s[pb+j]){
				blz = true;
				break;
			}
		}
		if(!blz) return false;
	}
	return true;
}

void generateSequence(){
	int i;
	tam = 0;
	s[1] = '\0';
	while(tam < MAX-1){
		tam++;
		i = 0;
		do{
			if(i < 3){
				s[tam-1] = al[i++];
			}else{
				do{
					while(s[tam-1] >= 'P') tam--;
					s[tam-1]++;
					i = 0;
				}while(!isValid());
			}
		}while(!isValid());
		s[tam] = '\0';
	}
}

void printSequence(int N){
	for(int i = 0; i < N; i++){
		putchar(s[i]);
	}
	putchar('\n');
}

int main(void){
	int N;
	generateSequence();
	while(scanf("%d", &N), N){
		printSequence(N);
	}
	return 0;
}
