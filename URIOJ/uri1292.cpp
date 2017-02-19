#include<stdio.h>
#include<math.h>

int main (void){
    double n;
    const double PI = acos(-1);
    while (scanf("%lf", &n) != EOF){
        printf("%.10lf\n", n * (sin(108 * PI/180) / sin(63 * PI/180)));
    }
    return 0;
}
