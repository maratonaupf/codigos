#include<stdio.h>
#include<string.h>
#define DEBP //DEBug Print

using namespace std;

char upper[][3] = { ".*", "*.", "*.", "**", "**", "*.", "**", "**", "*.", ".*" }, 
	lower[][3] = {"**", "..", "*.", "..", ".*", ".*", "*.", "**", "**", "*." };

void toBraille(int D, char* s){
	int i;
	for(i = 0; i < D; i++){
		printf("%s%c", upper[s[i] - '0'], i < D-1 ? ' ' : '\n');
	}
	for(i = 0; i < D; i++){
		printf("%s%c", lower[s[i] - '0'], i < D-1 ? ' ' : '\n');
	}
	for(i = 0; i < D; i++){
		printf("..%c", i < D-1 ? ' ' : '\n');
	}
}

char b1[112][3];
char b2[112][3];

void fromBraille(int D){
	int i, j;
	for(i = 0; i < D; i++){
		for(j = 0; j < 10; j++){
			if(strcmp(b1[i], upper[j]) == 0 && strcmp(b2[i], lower[j]) == 0){
				putchar('0'+j);
				break;
			}
		}
	}
	putchar('\n');
}

int main(void){
	int D, i; 
	char mode;
	char s[112];
	
	while(scanf("%d", &D), D){
		getchar();
		mode = getchar();
		if(mode == 'S'){
			scanf("%s", s);
			toBraille(D, s);
		}
		else{
			for(i = 0; i < D; i++){
				scanf("%s", b1[i]);
				//printf("%s%c", b1[i], i < D-1? ' ' : '\n');
			}
			for(i = 0; i < D; i++){
				scanf("%s", b2[i]);
				//printf("%s%c", b2[i], i < D-1? ' ' : '\n');
			}
			for(i = 0; i < D; i++){
				scanf("%*s");
			}
			fromBraille(D);
		}
	}
	return 0;
}
