#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
//#define DEBP // DEBug Prints

int cmpstringp(const void *p1, const void *p2){
	return strcasecmp((char *) p1, (char *) p2);
}

int main(void){
	int quant = 0;
	char str[MAX][82];
	while(fgets(str[quant], 82, stdin) != NULL){
		quant++;
	}
	qsort(str, quant, sizeof(str[0]), cmpstringp);
#ifdef DEBP
	for(int i = 0; i < quant; i++){
		printf("%s", str[i]);
	}
#endif // DEBP;
	printf("%s", str[quant-1]);
	return 0;
}
