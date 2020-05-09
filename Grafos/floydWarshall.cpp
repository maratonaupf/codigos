/*
 * Leonardo Deliyannis Constantin
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1655
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#define MAX 112
#define INFTO (int)(1e9) // 1000000000

int n, m;
double AG[MAX][MAX];

void floydWarshall(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                AG[i][j] = max(AG[i][j], AG[i][k] * AG[k][j]);
}

int main(){
    int a, b;
    double p;
    while(cin >> n && n != 0){
        cin >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                AG[i][j] = 0.0;
            }
        }
        while(m--){
            cin >> a >> b >> p;
            p *= 0.01;
            AG[a][b] = p;
            AG[b][a] = p;
        }
        floydWarshall();
        cout << fixed << setprecision(6) << (AG[1][n] * 100.0);
        cout << " percent\n";
    }
    return 0;
}
