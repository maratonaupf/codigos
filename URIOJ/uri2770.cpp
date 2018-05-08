/*
 * Leonardo Deliyannis Constantin
 * URI 2770 - Tamanho da Placa
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int x, y, m;
    int a, b;
    while(scanf("%d %d %d", &x, &y, &m) != EOF){
        if(x > y) 
            swap(x, y);
        while(m--){
            scanf("%d %d", &a, &b);
            if(a > b)
                swap(a, b);
            printf("%s\n", a <= x && b <= y ? "Sim" : "Nao");
        }
    }
    return 0;
}
