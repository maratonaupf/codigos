#include <iostream>
 
 
#define ITENS_MAX 100
#define CAP_MAX 50
 
 
using namespace std;
 
int tabela[ITENS_MAX+1][CAP_MAX+1];
int peso[ITENS_MAX+1];
int valor[ITENS_MAX+1];
 
int bottom_up(int cap, int itens)
{
    int val,soma;
    for(int i = 1; i<=itens; i++)
    {
        for(int j=1; j<=cap; j++)
        {
            val = tabela[i-1][j];
 
            if( peso[i] <= j){
                soma = tabela[i-1][j-peso[i]] + valor[i];
                if( val < soma)
                    val = soma;
            }
            tabela[i][j] = val;
        }
    }
    return tabela[itens][cap];
}
 
 
int main()
{
    for(int i=0; i<=ITENS_MAX; i++)
        tabela[i][0]=0;
    for(int j=0; j<=CAP_MAX; j++)
        tabela[0][j]=0;
    int casos;
    cin >> casos;
    int n,cap,vida;
    while(casos--)
    {
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            cin >> valor[i] >> peso[i];
        }
        int brinquedos=bottom_up(50, n);
 
         int i = n;
         int j = 50;
         int aux = tabela[i][j];
         int qtd=0;
 
         while(aux){
             if(aux != tabela[i-1][j]){
                 qtd++;//i = é o item
                 j -= peso[i];
             }
             i--;
             aux = tabela[i][j];
         }
 
         cout << brinquedos << " brinquedos" << endl
              << "Peso: " << 50-j << " kg" << endl
              << "sobra(m) " << n-qtd << " pacote(s)" << endl << endl;
 
    }
}
