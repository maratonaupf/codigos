//#include<stdio.h>
#include<iostream>
#include<iomanip>
//#include<math.h>
#include<cmath>

using namespace std;

int main (void){
    double n;
    const double PI = acos(-1);
    //while (scanf("%lf", &n) != EOF){
    while (cin >> n){
        //printf("%.10lf\n", n * (sin(108 * PI/180) / sin(63 * PI/180)));
        cout << fixed << setprecision(10);
        cout << n * (sin(108.0 * PI/180.0) / sin(63.0 * PI/180.0)) << endl;
    }
    return 0;
}
