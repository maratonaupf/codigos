#include<stdio.h>
#include<string.h>
#define MAX 51
#define min(a, b) ((a) < (b) ? a : b)

void manipula(const char *a, const char *b, char *s){
    int i, menor, ta, tb;
    ta = strlen(a);
    tb = strlen(b);
    menor = min(ta, tb);
    for(i = 0; i < menor; i++){
        s[i*2] = a[i];
        s[i*2+1] = b[i];
    }
    s[menor*2] = '\0';
    strcat(s, (tb == menor) ? a+menor : b+menor);
}

int main(void){
    char a[MAX], b[MAX], s[MAX*2];
    int N;
    scanf("%d", &N);
    while(N--){
        getchar();
        scanf("%s %s", a, b);
        manipula(a, b, s);
        printf("%s\n", s);
    }
    return 0;
}
