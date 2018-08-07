/*
 * Leonardo Deliyannis Constantin
 * URI 2593 - Eachianos I
*/

#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define MAX 10234
#define LEN 54

char T[MAX], P[LEN];
int b[MAX], n, m;

void kmpPreprocess(){
    int i = 0, j = -1; b[0] = -1;
    while(i < m){
        while(j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

vector<int> kmpSearch(){
    vector<int> v;
    int i = 0, j = 0;
    while(i < n){
        while(j >= 0 && T[i] != P[j]) j = b[j];
        i++; j++;
        if(j == m){
            v.push_back(i - j);
            j = b[j];
        }
    }
    return v;
}

int main(){
    int words;
    T[0] = P[0] = ' ';
    while(fgets(T+1, MAX, stdin) != NULL){
        scanf("%d ", &words);
        n = (int)strlen(T);
        T[n-1] = ' ';
        while(words--){
            scanf("%s ", P+1);
            P[m = (int)strlen(P)] = ' ';
            P[++m] = 0;
            kmpPreprocess();
            vector<int> v = kmpSearch();
            if(v.empty())
                printf("-1\n");
            else{
                for(int i = 0; i < (int)v.size(); i++){
                    printf("%d%c", v[i], i < (int)v.size()-1 ? ' ' : '\n');
                }
            }
        }
    }
    return 0;
}
