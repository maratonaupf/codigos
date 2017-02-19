/* URI 1828 - Bazinga! */
#include<stdio.h>
#include<string.h>
//#define DEBP

int main(void){
	int T, c, i, j, m[5][5];
	char sh[8], raj[8], r[3][16], v[5][8];
	
	strcpy(r[1], "Bazinga");
	strcpy(r[2], "Raj trapaceou");
	strcpy(r[0], "De novo");
	
	strcpy(v[0], "tesoura");
	strcpy(v[1], "papel");
	strcpy(v[2], "pedra");
	strcpy(v[3], "lagarto");
	strcpy(v[4], "Spock");
	
	memset(m, 0, sizeof(m));
	
	for(i=0; i<5; i++){
		if(i < 4){
			m[i][i + 1] = 1;
			m[i + 1][i] = 2;
		}
		if(i < 2){
			m[i][i + 3] = 1;
			m[i + 3][i] = 2;
		}
		if(i < 3){
			m[i + 2][i] = 1;
			m[i][i + 2] = 2;
		}
	}
	m[4][0] = 1;
	m[0][4] = 2;

#ifdef DEBP
	for(i=0; i<5; i++)
		for(j=0; j<5; j++)
			printf("%d%c", m[i][j], (j<4) ? ' ' : '\n' );
	
#endif // DEBP;
#ifndef DEBP
	scanf("%d", &T);
	getchar();
	for(c=1; c<=T; c++){
		scanf("%s %s", sh, raj);
		for(i=0; i<5 && strcmp(sh, v[i]); i++);
		for(j=0; j<5 && strcmp(raj, v[j]); j++);
		printf("Caso #%d: %s!\n", c, r[m[i][j]]);
	}
#endif // DEBP;
	return 0;
}

