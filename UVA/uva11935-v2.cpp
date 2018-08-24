/*
 * Leonardo Deliyannis Constantin
 * UVa 11935 - Through the Desert
*/

#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
#define MAX 52
#define EPS 1e-4

int n, km[MAX], fu[MAX];
string ev[MAX];

bool simulate(double cap){
    double tank = cap, cons = (double)fu[0];
    int leaks = 0;
    for(int i = 0; i < n; i++){
        if(i > 0){
            tank -= cons * (double)(km[i] - km[i-1]);
            tank -= (double)(leaks * (km[i] - km[i-1]));
        }
        if(tank < 0.0) return false;
        if(ev[i] == "Fuel") cons = (double)fu[i] / 100.0;
        if(ev[i] == "Leak") leaks++;
        if(ev[i] == "Gas")  tank = cap;
        if(ev[i] == "Mechanic")
            leaks = 0;
    }
    return true;
}

int main(){
    char s[MAX];
    while(true){
        for(n = 0; ; n++){
            scanf("%d %s", &km[n], s);
            ev[n] = s;
            if(ev[n] == "Fuel"){
                scanf("%*s %d", &fu[n]);
                if(km[n] == 0 && fu[n] == 0)
                    return 0;
            }
            if(ev[n] == "Gas")
                scanf("%*s");
            if(ev[n] == "Goal"){
                n++;
                break;
            }
        }
        double lo = 0.0, hi = 1e4;
        double mid, last = -1.0;
        while(fabs((mid = (lo+hi)/2.0) - last) > EPS){
            if(simulate(mid))
                hi = mid;
            else
                lo = mid;
            last = mid;
        }
        printf("%.3lf\n", mid);
    }
    return 0;
}
