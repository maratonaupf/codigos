// Problema D
#include <cstdio>
#include <string>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int y, t;
	double k;
	string s;
	scanf("%d", &y);
	while(y--)
	{
		map<string, double> mapa;
		map<string, double>::iterator it;
		scanf("%d", &t);
		
		for(int i = 0; i < t; i++)
		{
			getchar(); // '\n'
			getline(cin, s);
			scanf("%lf", &k);
			mapa[s] = k;		
		}
		double capacidade;
		double pesoTotal = 0.0;
		int total;
		scanf("%lf", &capacidade);
		while(1)
		{
			getchar();
			getline(cin, s);
			scanf("%d", &total);
			
			if(s == "-" && total == 0)
				break;
			it = mapa.find(s);
			if(it != mapa.end())
				pesoTotal = (mapa[s] * total) + pesoTotal;			
			else
				cout << "NAO LISTADO: " << s << endl;
		}
		printf("Peso total: %.2lf kg\n", pesoTotal);
		printf("Numero de trenos: %d\n\n", (int)ceil(pesoTotal / capacidade));
	}
	return 0;
}
