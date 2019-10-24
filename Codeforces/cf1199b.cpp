#include <stdio.h>
#include <math.h>

int main(){
    double h, l;
    while(scanf("%lf %lf", &h, &l) != EOF){
        double a = (l*l + h*h) / ((double) (2.0)*h);
        printf("%.13lf\n", a-h);
    }    
    return 0;
}
