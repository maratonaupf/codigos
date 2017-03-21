#include<stdio.h>
#define MAX 112

int main(void){
	int lines, cont;
	char str[MAX];
	while(scanf("%d\n", &lines) != EOF){
		cont = 0;
		while(lines--){
			fgets(str, MAX, stdin);
			for(int i = 0; str[i]; i++){
				if(str[i] == '{') cont++;
				if(str[i] == '}') cont--;
			}
		}
		printf("%c\n", cont == 0 ? 'S' : 'N');
	}
    return 0;
}
