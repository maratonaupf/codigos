#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stack>
using namespace std;
int main()
{
    bool aux=false;
    int n,V,E;
    unsigned char ori,dest;
    cin >> n;
    for(int case_number=1;case_number<=n;case_number++)
    {
        cin >> V >> E;
        bool nodos[V];
        memset(nodos,false,sizeof(nodos));
        vector<int> arestas[V];
        for(int i=0;i<E;i++)
        {
            cin >> ori >> dest;
            arestas[ori-'a'].push_back(dest-'a');
            arestas[dest-'a'].push_back(ori-'a');
        }
        cout << "Case #" << case_number << ":" << endl;
        int connected=0;
        for(int i=0;i<V;i++)
        {
            stack<int> dfs;
            if(!nodos[i])
            {
                vector<char> saida;
                dfs.push(i);
                nodos[i]=true;
                while(!dfs.empty())
                {
                    int nod=dfs.top();
                    dfs.pop();
                    saida.push_back(nod+'a');
                    for(int &it: arestas[nod])
                    {
                        if(!nodos[it])
                        {
                            dfs.push(it);
                            nodos[it]=true;
                        }
                    }
                }
                sort(saida.begin(),saida.end());
                for(char &a:saida)
                    cout << a << ',';
                cout << endl;
                connected++;
            }
        }
        cout << connected << " connected components" << endl << endl;
    }
 
 
    return 0;
 
}
