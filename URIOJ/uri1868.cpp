/*
 * Leonardo Deliyannis Constantin
 * URI 1868 - Espiral Quadrada 
*/

#include <stdio.h>
#define MAX 25

int N, xi, xj;
int iterations;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

void printGrid(){
    iterations++;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            putchar(xi == i && xj == j ? 'X' : 'O');
        }
        putchar('\n');
    }
    printf("@\n");
}

int main(){
    int len, k, steps;
    while(scanf("%d", &N), N != 0){
        xi = xj = N / 2;
        iterations = 0;
        printGrid();
        for(len = 2; iterations < N*N; len += 2){
            xj++;
            printGrid();
            for(k = 0; k < 4; k++){
                for(steps = 0; steps < len; steps++){
                    if(k == 0 && steps == 0)
                        continue;
                    xi += di[k];
                    xj += dj[k];
                    printGrid();
                }
            }
        }
    }
    return 0;
}
