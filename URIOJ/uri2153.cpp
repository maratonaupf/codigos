#include<stdio.h>
#include<string.h>
#define MAX 33

size_t squareWord(char *s, size_t tam){
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
		if(!blz) return i;
	}
	return 0;
}

void unsquare(char *s){
    size_t tam = strlen(s);
    size_t len;
    while((len = squareWord(s, tam))){
		tam -= len;
		s[tam] = '\0';
	}
}

int main(void){
    char s[MAX];
    while(scanf("%s", s) != EOF){
        getchar();
		unsquare(s);
        puts(s);
    }
    return 0;
}
