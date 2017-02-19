#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1123
#define DEBP // DEBug Print

int comp(const void *a, const void *b) {
	return strcasecmp((char *)a, (char *)b);
}

int main(void){
	int quant = 0;
	char v[MAX][82];
	
	while(fgets(v[quant++], 82, stdin) != NULL);
	qsort(v, quant, sizeof(v[0]), comp);
	
	printf("%s", v[quant-1]);
	return 0;
}
