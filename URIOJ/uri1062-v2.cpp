/*
 * Leonardo Deliyannis Constantin
 * URI 1062 - Trilhos
*/

#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int N, i, j;
    while(scanf("%d", &N), N){
        vector<int> a(N, 0);
        while(scanf("%d", &a[0]), a[0]){
            for(i = 1; i < N; i++){
                scanf("%d", &a[i]);
            }
            vector<int> s;
            for(i = 1, j = 0; i <= N; i++){
                s.push_back(i);
                while(j < N && !s.empty() && s.back() == a[j]){
                    s.pop_back();
                    j++;
                }
            }
            printf("%s\n", j == N ? "Yes" : "No");
        }
        printf("\n");
    }
    return 0;
}
