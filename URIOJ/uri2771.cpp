/*
 * Leonardo Deliyannis Constantin
 * URI 2771 - Média
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 112

bool rev(double a, double b){
    return a > b;
}

int main(){
    int N, K, i, j, k;
    int a[MAX];
    double avg;
    while(scanf("%d %d", &N, &K) != EOF){
        for(i = 0; i < N; i++){
            scanf("%d", &a[i]);
        }
        vector<double> v;
        for(i = 0; i < N; i++)
            for(j = i+1; j < N; j++)
                for(k = j+1; k < N; k++){
                    avg = (double)(a[i] + a[j] + a[k]) / 3.0;
                    v.push_back(avg);
                }
        sort(v.begin(), v.end(), rev);
        printf("%.1lf\n", v[K-1]);
    }
    return 0;
}
