/*
 * Leonardo Deliyannis Constantin
 * Exemplo de grafo usando DFS
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> vi;

int N, E;
vector<vi> LG;
vector<bool> vis;
vi par;

// Retorna se a componente conexa atual do grafo
// possui ou não possui ciclo(s)
bool dfs(int s){
    bool ret = false;
    vis[s] = true;
    par[s] = s;
    stack<int> st;
    st.push(s);
    while(!st.empty()){
        int u = st.top();
        st.pop();
        for(int v : LG[u]){
            if(!vis[v]){
                vis[v] = true;
                par[v] = u;
                st.push(v);
            }
            else if(par[u] != v)
                ret = true;
        }
    }
    return ret;
}

int main(){
    int u, v, i, ncomp;
    bool temCiclo;
    while(cin >> N >> E){
        LG.assign(N, vi());
        for(i = 0; i < E; i++){
            cin >> u >> v;
            u--, v--;
            LG[u].push_back(v);
            LG[v].push_back(u);
        }
        vis.assign(N, false);
        par.assign(N, false);
        temCiclo = false;
        ncomp = 0;
        for(u = 0; u < N; u++){
            if(!vis[u]){
                temCiclo |= dfs(u);
                ncomp++;
            }
        }
        cout << "Ciclico: " << (temCiclo ? "Sim" : "Nao") << endl;
        cout << "Componentes conexas: " << ncomp << endl;
    }
    return 0;
}
