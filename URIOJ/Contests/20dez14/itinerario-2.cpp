#include <cstdio>
#include <vector>
#include <queue>
 
using namespace std;
 
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
vi visitados;
priority_queue<ii> pq;
vector<vii> AdjList;
 

void process(int vtx){
    visitados[vtx] = 1;
    for (int j = 0; j < (int)AdjList[vtx].size(); j++){
        ii v = AdjList[vtx][j];
 
        if (!visitados[v.first])
            pq.push(ii(-v.second, -v.first));
    }
}
 
long long int prim(int V){
    int u, w;
   visitados.assign(V, 0);
   process(0);
   long long int mst_cost = 0;
 
   while (!pq.empty()){
      ii front = pq.top(); pq.pop();
      u = -front.second, w = -front.first; 
 
      if (!visitados[u])
         mst_cost += w, process(u);
   }
   return mst_cost;
}
 
 
int main(){
    int V, A, u, v, w;
 
    while (scanf("%d %d", &V, &A) && V && A){
        AdjList.assign(V, vii());
 
        for(int i = 0; i < A; i++){
            scanf("%d %d %d", &u, &v, &w);
            AdjList[u].push_back(ii(v, w));
            AdjList[v].push_back(ii(u, w));
        }
 
        printf("%lld\n", prim(V));
    }
 
    return 0;
}
