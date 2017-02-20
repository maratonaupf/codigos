#include<stdio.h>

bool opposites(char *a, char *b){
	return (a[0] == 'n' && b[0] == 's') 
		|| (a[0] == 's' && b[0] == 'n')
		|| (a[0] == 'o' && b[0] == 'l')
		|| (a[0] == 'l' && b[0] == 'o');
}

int sim(char* a, char *b){
	return a[0] == b[0] ? 0 : opposites(a, b) ? 180 : 90;
}

int main(void){
	char a[10], b[10];
	while(scanf("%s %s", a, b) != EOF){
		printf("%d\n", sim(a, b));
	}
	return 0;
}
