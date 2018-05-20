/*
 * Leonardo Deliyannis Constantin
 * URI 2758 - Entrada e Saída de Números Reais
*/

#include <stdio.h>

int main(){
    float A, B;
    double C, D;
    while(scanf("%f %f", &A, &B) != EOF){
        scanf("%lf %lf", &C, &D);
        printf("A = %.6f, B = %.6f\nC = %.6lf, D = %.6lf\n", A, B, C, D);
        printf("A = %.1f, B = %.1f\nC = %.1lf, D = %.1lf\n", A, B, C, D);
        printf("A = %.2f, B = %.2f\nC = %.2lf, D = %.2lf\n", A, B, C, D);
        printf("A = %.3f, B = %.3f\nC = %.3lf, D = %.3lf\n", A, B, C, D);
        printf("A = %.3E, B = %.3E\nC = %.3E, D = %.3E\n", A, B, C, D);
        printf("A = %.0f, B = %.0f\nC = %.0lf, D = %.0lf\n", A, B, C, D);
    }
    return 0;
}
