#include <iostream>
#include <map>
using namespace std;
map<int,int> ratos;
void conta_ratos(int f)
{
    auto it=ratos.find(f);
    if(it==ratos.end())
        ratos[f]=1;
    else
        it->second++;
}

map<int,int>::iterator menor_igual(int c)
{
    auto it=ratos.upper_bound(c);
    if(it!=ratos.begin())
        return --it;
    return ratos.end();
}

void alimentar(int c,int &saciados)
{
    auto it=menor_igual(c);
    if(it==ratos.end())
    {
        --it;
        conta_ratos(it->first-c);
    } else saciados++;
    if(--it->second==0)
        ratos.erase(it);

}
int main()
{
    int n, m;
    int fome,alimento;
    while(cin >> n >> m)
    {
        ratos.clear();
        for(int i=0;i<n;i++)
        {
            cin >> fome;
            conta_ratos(fome);
        }
        int saciados=0;
        for(int i=0;i<m;i++)
        {
            cin >> alimento;
            if(saciados!=n)
                alimentar(alimento,saciados);
        }
        cout << saciados << endl;
    }
}
