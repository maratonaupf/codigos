#include<stdio.h>
#include<string.h> // strcmp()
#define MAX 112 
// Dá e sobra. O máximo é de 102 caracteres, já
// contando com o '\0' (caractere nulo de terminação)

char z[MAX]; // variável global
// função de processamento
void processa(int d, char s[]){
	// tamanho da string z começa em 0 
	unsigned i, tam = 0;
	// somamos o inteiro d 
	// com o valor ASCII de '0'
	d += '0';
	// para cada caractere da string original
	for(i = 0; s[i] != '\0'; i++){
		// se o caractere não for o dígito estragado
		// e a string nova não estiver vazia, 
		// ou o caractere original não for zero
		if(s[i] != d && (tam > 0 || s[i] != '0')){
			// adicionamos o caractere na string nova, 
			// e incrementamos seu tamanho
			z[tam++] = s[i];
		}
	}
	// se o tamanho da string nova ainda for zero,
	// adicionamos apenas o caractere '0'
	if(tam == 0) z[tam++] = '0';
	// terminamos a string com o 
	// caractere nulo de terminação
	z[tam] = '\0';
}

int main(void){
	int d; 
	char s[MAX];
	// lemos o dígito e a string na entrada do while, 
	// e ele roda enquanto ambos forem diferentes de 0
	while(scanf("%d %s", &d, s), d != 0 || strcmp(s, "0") != 0){
		// o processamento poderia muito bem ser feito
		// aqui dentro, mas para deixar o código mais 
		// organizado, fiz uma função apenas para isso
		processa(d, s);
		// imprime a string global que preparamos
		printf("%s\n", z);
	}
	return 0;
}

