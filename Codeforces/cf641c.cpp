/*
 * Leonardo Deliyannis Constantin
 * CodeForces 641 C - Little Artem and Dance
 */

#include <stdio.h>
#include <algorithm>
using namespace std;

int next(int boy, int positions, int N){
    int aux = (boy+positions) % N;
    return (aux == 0) ? N : aux;
}

int main(){
    int N, Q, a, b, m, x, p, i;
    int a2, b2;
    while(scanf("%d %d", &N, &Q) != EOF){
        a = 0;
        b = 1;
        while(Q--){
            scanf("%d", &m);
            if(m == 1){
                scanf("%d", &x);
                p = (N-x)%N;
                if(p&1){
                    a2 = next(b, p-1, N);
                    b2 = next(a, p+1, N);
                    a = a2; 
                    b = b2;
                }
                else{
                    a = next(a, p, N);
                    b = next(b, p, N);
                }
            }
            else swap(a, b);
        }
        for(i = 0; i < N; i+=2){
            printf("%d %d", ((a+i)%N)+1, ((b+i)%N)+1);
            printf("%c", (i < N-2) ? ' ' : '\n');
        }
    }
    return 0;
}
