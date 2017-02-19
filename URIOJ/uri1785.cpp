#include<cstdio>
#include<cstdlib>
#include<cstring>

int cmp (const void * a, const void * b){
	return ( *(char*)a - *(char*)b );
}

int cmp_rev (const void * a, const void * b){
	return ( *(char*)b - *(char*)a );
}

/* NCDD == numero com digitos de */

int maior_ncdd(int X){
	char s[5];
	sprintf(s, "%04d", X);
	qsort(s, 4, sizeof(char), cmp_rev);
	sscanf(s, "%d", &X);
	return X;
}

int menor_ncdd(int X){
	char s[5];
	sprintf(s, "%04d", X);
	qsort(s, 4, sizeof(char), cmp);
	for(int i=0; s[i]=='0'; i++) s[i]=' ';
	sscanf(s, "%d", &X);
	return X;
}

int krapekar(int X){
	int cnt = 0;
	while(X != 6174) {
		int maior = maior_ncdd(X);
		int menor = menor_ncdd(X);
		X = maior - menor;
		if(X == 0){ cnt = -1;
			break;
		}
		cnt++;
		//puts("batããããtããa");
	}
	return cnt;
}

int main(void){	
	int T, X, CT = 0;
	scanf("%d", &T);
	while(CT++ < T){
	//while(scanf("%d", &X)!=EOF){
		scanf("%d", &X);
		//~ printf("Original: %04d\n", X);
		//~ printf("Maior: %04d\n", maior_ncdd(X));
		//~ printf("Menor: %04d\n\n", menor_ncdd(X));
		printf("Caso #%d: %d\n", CT, krapekar(X));
	}
	return 0;
}
