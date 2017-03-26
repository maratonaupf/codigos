#include<stdio.h>
#include<string.h>

#define TAMAX 12345 /* precisa ser alterado a cada problema */
#define BASE 100000000 /* 10^8 */

typedef struct bigint {
  unsigned long long V[TAMAX];
  int tam;
} bigint;

/* lê o bigint apontado por I
   não tem problema se em *I já existe algum valor ou não
   devolve 1 se consegue ler ou 0 c.c. <== útil para pôr num while
   CUIDADO: considera que o fim do bigint é marcado por \n
            se não for o caso, NÃO use fgets
            por ex: se for um espaço que marca o fim do bigint,
                    use getchar() dentro dum for */
int leia_bigint(bigint *I) {
  char S[8*TAMAX];
  int i, j, pot;
  fgets(S, 8*TAMAX, stdin);
  i = strlen(S) - 2;
  if (i == -1) return 0;
  I->tam = 0;
  while (i >= 0) {
    pot = 1;
    I->V[I->tam] = 0;
    for (j = 1; j <= 8 && i >= 0; j++, i--) {
      I->V[I->tam] = I->V[I->tam] + pot*(S[i] - '0');
      pot *= 10;
    }
    I->tam++;
  }
  return 1;
}

/* imprime um bigint
   é necessário que *I seja um bigint válido */
void imprima_bigint(bigint *I) {
  int i;
  printf("%llu", I->V[I->tam - 1]);
  for (i = I->tam - 2; i >= 0; i--)
    printf("%08llu", I->V[i]);
  printf("\n");
}

/* retorna 1 se *I1 < *I2 ou 0 caso contrário
   necessário que ambos sejam bigint's válidos */
int menor_bigint(bigint *I1, bigint *I2) {
  int i;
  if (I1->tam < I2->tam) return 1;
  if (I1->tam > I2->tam) return 0;
  for (i = I1->tam - 1; i >= 0 && I1->V[i] == I2->V[i]; i--);
  if (i == -1) return 0;
  if (I1->V[i] < I2->V[i]) return 1;
  return 0;
}

/* retorna 1 se *I1 = *I2 ou 0 caso contrário
   necessário que ambos sejam bigint's válidos */
int igual_bigint(bigint *I1, bigint *I2) {
  int i;
  if (I1->tam < I2->tam) return 0;
  if (I1->tam > I2->tam) return 0;
  for (i = I1->tam - 1; i >= 0 && I1->V[i] == I2->V[i]; i--);
  if (i == -1) return 1;
  return 0;
}

/* copia *I1 para *I2
   necessário que *I1 seja um bigint válido
   não tem problema se em *I2 já existe algum valor ou não */
void copie_bigint(bigint *I1, bigint *I2) {
  int i;
  I2->tam = I1->tam;
  for (i = 0; i < I1->tam; i++)
    I2->V[i] = I1->V[i];
}

/* remove eventuais zeros à esquerda de *I
   necessário que *I seja um bigint válido,
   apenas podendo ter zeros à esquerda */
void conserte_zeros(bigint *I) {
  int i;
  for (i = I->tam - 1; i >= 0 && I->V[i] == 0; i--);
  if (i == -1) I->tam = 1;
  else I->tam = i + 1;
}

/* efetua *I1 + *I2 e armazena o resultado em *I3
   necessário que *I1 e *I2 sejam bigint's válidos
   necessário que max(I1->tam, I2->tam) < TAMAX
   não tem problema se em *I3 já existe algum valor ou não
   funciona mesmo se o ponteiro I3 = I1 ou I3 = I2 */
void some_bigint(bigint *I1, bigint *I2, bigint *I3) {
  int i;
  unsigned long long carry=0, valor1, valor2;
  for (i = 0; i < I1->tam || i < I2->tam; i++) {
    valor1 = i < I1->tam ? I1->V[i] : 0;
    valor2 = i < I2->tam ? I2->V[i] : 0;
    I3->V[i] = valor1 + valor2 + carry;
    carry = I3->V[i] / BASE;
    I3->V[i] = I3->V[i] % BASE;
  }
  I3->V[i] = carry;
  I3->tam = i + 1;
  conserte_zeros(I3);
}

/* efetua *I1 + *I2 e armazena o resultado em *I3
   necessário que *I1 e *I2 sejam bigint's válidos
   não tem problema se em *I3 já existe algum valor ou não
   funciona mesmo se o ponteiro I3 = I1 ou I3 = I2
   funciona apenas se garantidamente *I1 >= *I2 */
void subtraia_bigint(bigint *I1, bigint *I2, bigint *I3) {
  int i;
  unsigned long long carry=0, valor2;
  for (i = 0; i < I1->tam || i < I2->tam; i++) {
    valor2 = i < I2->tam ? I2->V[i] : 0;
    if (I1->V[i] < valor2 + carry) {
      I3->V[i] = BASE + I1->V[i] - valor2 - carry;
      carry = 1;
    } else {
      I3->V[i] = I1->V[i] - valor2 - carry;
      carry = 0;
    }
  }
  I3->tam = I1->tam;
  conserte_zeros(I3);
}

/* efetua *I1 * a e armazena o resultado em *I2
   necessário que *I1 seja um bigint válido e 0 <= a < BASE
   necessário que I1->tam < TAMAX
   não tem problema se em *I2 já existe algum valor ou não
   funciona mesmo se o ponteiro I2 = I1 */
void mult_escalar(bigint *I1, unsigned long long a, bigint *I2) {
  int i;
  unsigned long long carry=0;
  for (i = 0; i < I1->tam; i++) {
    I2->V[i] = I1->V[i] * a + carry;
    carry = I2->V[i] / BASE;
    I2->V[i] = I2->V[i] % BASE;
  }
  I2->V[i] = carry;
  I2->tam = i + 1;
  conserte_zeros(I2);
}

/* desloca *I i dígitos (ref. base BASE, não base 10) para a esquerda
   necessário que *I seja um bigint válido e que i >= 0
   necessário que I->tam + i <= TAMAX */
void lshift_bigint(bigint *I, int i) {
  int j;
  for (j = I->tam - 1 + i; j >= i; j--)
    I->V[j] = I->V[j-i];
  for (; j >= 0; j--) I->V[j] = 0;
  I->tam = I->tam + i;
  conserte_zeros(I);
}

/* efetua *I1 * *I2 e armazena o resultado em *I3
   necessário que *I1 e *I2 sejam bigint's válidos
   necessário que I1->tam + I2->tam < TAMAX
   não tem problema se em *I3 já existe algum valor ou não
   funciona mesmo se o ponteiro I3 = I1 ou I3 = I2 */
void mult_bigint(bigint *I1, bigint *I2, bigint *I3) {
  bigint tmp, soma;
  int i;
  soma.tam = 1; soma.V[0] = 0;
  for (i = 0; i < I1->tam; i++) {
    mult_escalar(I2, I1->V[i], &tmp);
    lshift_bigint(&tmp, i);
    some_bigint(&soma, &tmp, &soma);
  }
  copie_bigint(&soma, I3);
}

/* efetua a divisão inteira de *I1 por *I2 e armazena o quociente em
   *quoc e o resto em *mod
   necessário que *I1 e *I2 sejam bigint's válidos
   não tem problema se em *quoc ou *mod já existem valores ou não
   funciona mesmo se há coincidências entre os ponteiros */
void div_bigint(bigint *I1, bigint *I2, bigint *quoc, bigint *mod) {
	unsigned long long d;
	int diftam;
	bigint tmp, dtmp;
	copie_bigint(I1, mod);
	quoc->V[0] = 0;
	quoc->tam = 1;
	while (menor_bigint(I2, mod) || igual_bigint(I2, mod)) {
		if (mod->V[mod->tam-1] >= I2->V[I2->tam-1])
			d = mod->V[mod->tam-1] / I2->V[I2->tam-1];
		else
			d = (mod->V[mod->tam-1]*BASE + mod->V[mod->tam-2])
				  / I2->V[I2->tam-1];
		dtmp.V[0] = d;
		dtmp.tam = 1;
		while (1) {
			mult_escalar(I2, d, &tmp);
			diftam = mod->tam - tmp.tam;
			lshift_bigint(&tmp, diftam);
			lshift_bigint(&dtmp, diftam);
			if (menor_bigint(mod, &tmp)) {
              d--;
              dtmp.V[0] = d;
              dtmp.tam = 1;
            }
			else break;
		}
		subtraia_bigint(mod, &tmp, mod);
		some_bigint(quoc, &dtmp, quoc);
	}
}

/* exemplo de uso */
int main(void) {
  bigint I1, I2, quoc, mod;
  leia_bigint(&I1);
  leia_bigint(&I2);
  div_bigint(&I1, &I2, &quoc, &mod);
  imprima_bigint(&quoc);
  imprima_bigint(&mod);
  return 0;
}
