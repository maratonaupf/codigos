#include<stdio.h>
#include<iostream>

#define ITENS_MAX 123
#define CAP_MAX 123

using namespace std;

int tabela[ITENS_MAX+1][CAP_MAX+1];
int peso[ITENS_MAX+1];
int valor[ITENS_MAX+1];
int bottom_up(int cap, int itens)
{
	int val,soma;
	for(int i=1;i<=itens;i++)
	{
		for(int j=1;j<=cap;j++)
		{
			val = tabela[i-1][j];
			if(peso[i]<=j)
			{
				soma = tabela[i-1][j-peso[i]] + valor[i];
				if(val<soma)
					val = soma;
			}
			tabela[i][j] = val;
		}
	}
	return tabela[itens][cap];
}

int main(void){
	int l,n,caso=0;
	while(true)
	{
		for(int i=0;i<=ITENS_MAX;i++)
			tabela[i][0]=0;
		for(int i=0;i<=CAP_MAX;i++)
			tabela[0][i]=0;
		cin >> l >> n;
		if(l==0&&n==0)
			break;
		for(int i=1;i<=n;i++)
		{
			cin >> peso[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin >> valor[i];
		}
		int felicidade = bottom_up(l,n);
		cout << "Caso " << ++caso << " gera felicidade " << felicidade << endl;
	}
	return 0;
}

