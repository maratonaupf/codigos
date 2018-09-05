/*
 * Leonardo Deliyannis Constantin
 * URI 1127 - Plágio Musical
*/

#include <stdio.h>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
#define MAX 112345
#define MOD 12

typedef vector<string> vs;
typedef vector<int> vi;

int T[MAX], P[MAX], b[MAX], n, m;

unordered_map<string, int> note;
void setup(){
    vs key = {"C", "D", "E", "F", "G", "A", "B"};
    vi val = { 0,   2,   4,   5,   7,   9,   11};
    for(int i = 0; i < 7; i++){
        note[key[i]] = val[i];
        note[key[i]+"#"] = (val[i]+1) % MOD;
        note[key[i]+"b"] = (val[i]-1+MOD) % MOD;
    }
}

void preprocess(){
    int i = 0, j = -1; b[0] = -1;
    while(i < m){
        while(j >= 0 && P[i] != P[j]) j = b[j];
        i++, j++;
        b[i] = j;
    }
}

bool kmpSearch(){
    int i = 0, j = 0;
    while(i < n){
        while(j >= 0 && T[i] != P[j]) j = b[j];
        i++, j++;
        if(j == m) return true;
    }
    return false;
}

int main(){
    int i, j;
    char s[4];
    setup();
    while(scanf("%d %d", &n, &m), n != 0){
        for(i = 0; i < n; i++){
            scanf(" %s", s);
            T[i] = note[s];
        }
        for(i = 0; i < m; i++){
            scanf(" %s", s);
            P[i] = note[s];
        }
        bool plag = false;
        for(i = 0; i < 12 && !plag; i++){
            for(j = 0; j < m; j++)
                P[j] = (P[j]+1) % MOD;
            preprocess();
            plag |= kmpSearch();
        }
        printf("%c\n", plag ? 'S' : 'N');
    }
    return 0;
}
