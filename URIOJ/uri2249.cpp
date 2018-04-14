/*
 * Leonardo Deliyannis Constantin
 * URI 2249 - Número de Erdos
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define LEN 312
#define INFTO 0x3f3f3f3f

vector<string> ls;
map<string, vector<string> > LG;
map<string, int> dist;

bool cmp(string a, string b){
    return string(a, 3, a.size()) < string(b, 3, b.size());
}

void bfs(string s){
    for(string u : ls){
        dist[u] = INFTO;
    }
    dist[s] = 0;
    queue<string> Q;
    Q.push(s);
    while(!Q.empty()){
        string u = Q.front(); 
        Q.pop();
        for(int i = 0; i < (int)LG[u].size(); i++){
            string w = LG[u][i];
            if(dist[w] > dist[u] + 1){
                dist[w] = dist[u] + 1;
                Q.push(w);
            }
        }
    }
}

int main(){
    int A, test = 0;
    int i, j, tam;
    char s[LEN], w[LEN];
    while(scanf("%d ", &A), A != 0){
        test++;
        LG.clear();
        while(A--){
            fgets(s, LEN, stdin);
            tam = 0;
            ls.clear();
            for(i = 0; s[i]; i++){
                if(tam < 3 || isalpha(s[i])){
                    w[tam++] = s[i];
                }
                else if(tam >= 3 && !isalpha(s[i])){
                    w[tam] = '\0';
                    if(!LG.count(w))
                        LG[w].clear();
                    for(j = 0; j < (int)ls.size(); j++){
                        LG[w].push_back(ls[j]);
                        LG[ls[j]].push_back(w);
                    }
                    ls.push_back(w);
                    tam = 0;
                    i++;
                }
            }
        }
        ls.clear();
        for(auto it = LG.begin(); it != LG.end(); ++it){
            ls.push_back(it->first);
        }
        sort(ls.begin(), ls.end(), cmp);
        bfs(string("P. Erdos"));
        printf("Teste %d\n", test);
        for(string u : ls){
            if(u == "P. Erdos")
               continue;
            printf("%s: ", u.c_str());
            //for(auto it = LG[u].begin(); it!=LG[u].end(); ++it)
                //printf(" %s", it->c_str());
            if(dist[u] != INFTO)
                printf("%d\n", dist[u]);
            else
                printf("infinito\n");
        }
        printf("\n");
    }
    return 0;
}
