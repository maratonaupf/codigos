#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 512

typedef struct _country{
	char name[128];
	int medals[3];
} country;

int cmp(const void *p1, const void *p2){
	country a = *(country*)p1;
	country b = *(country*)p2;
	int i;
	for(i = 0; i < 3; i++)
		if(a.medals[i] != b.medals[i])
			return(b.medals[i] - a.medals[i]);
	return strcmp(a.name, b.name);
}

int main(void){
	int N, i, j;
	country v[MAX];
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		getchar();
		scanf("%s", v[i].name);
		for(j = 0; j < 3; j++){
			scanf("%d", &v[i].medals[j]);
		}
	}
	qsort(v, N, sizeof(v[0]), &cmp);
	for(i = 0; i < N; i++){
		printf("%s ", v[i].name);
		for(j = 0; j < 3; j++){
			printf("%d%c", v[i].medals[j], j < 2 ? ' ' : '\n');
		}
	}
	return 0;
}
