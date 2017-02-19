#include<stdio.h>
#include<string.h>
#define MAX 11234

int pos[2][MAX], tam[2];
char dummy[MAX];

bool isVowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void analyzeString(char *s){
    tam[0] = tam[1] = 0;
    for(int i = 0; s[i]; i++){
        bool flag = !isVowel(s[i]);
        pos[flag][tam[flag]++] = i;
    }
}

void shiftLetters(char *s, int op, int x){
    strcpy(dummy, s);
    for(int swaps = 0; swaps < tam[op]; swaps++){
        s[pos[op][(x + swaps) % tam[op]]] = dummy[pos[op][swaps]];
    }
}

int main(void){
    int t, q, op, x, acum[2];
    char s[MAX];
    scanf("%d", &t);
    
    for(int ncase = 1; ncase <= t; ncase++){
        scanf("%s", s);
        analyzeString(s);
        
        scanf("%d", &q);
        printf("Caso #%d:\n", ncase);
        
        acum[0] = acum[1] = 0;
        while(q--){
            scanf("%d", &op);
            if(op < 2){
                scanf("%d", &x);
                acum[op] += x;
            }
            else{
				shiftLetters(s, 0, acum[0]);
				shiftLetters(s, 1, acum[1]);
				puts(s);
				acum[0] = acum[1] = 0;
			}
        }
    }
    return 0;
}
