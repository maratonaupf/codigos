/*
 * Leonardo Deliyannis Constantin
 * URI 2774 - Precisão do Sensor
*/

#include <stdio.h>
#include <math.h>
#define MAX 112345

int main(){
    int H, M, QT, i;
    double x[MAX], avg, sum, ans;
    while(scanf("%d %d", &H, &M) != EOF){
        QT = H * 60 / M;
        avg = 0.0;
        for(i = 0; i < QT; i++){
            scanf("%lf", &x[i]);
            avg += x[i];
        }
        avg /= (double)QT;
        sum = 0.0;
        for(i = 0; i < QT; i++){
            sum += pow(x[i] - avg, 2.0);
        }
        ans = sqrt(sum / (double)(QT - 1));
        printf("%.5lf\n", ans);
    }
    return 0;
}
