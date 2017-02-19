#include <stdio.h>

int GCDsimp(int a, int b){
	return (b == 0) ? a : GCDsimp(b, a%b);
}

int main() {
    int num, den, apostas [100], cont=-1;
    while(scanf("%d %d", &num, &den) != EOF){
         apostas[++cont] = GCDsimp (num,den);
         puts(apostas[cont] > 5 ? "Noel" : "Gnomos");
    }
    for(int i = cont; i >= 0; i--) {
        printf("%d ", apostas[i]);
    }
    printf("\n");
    return 0;
}
