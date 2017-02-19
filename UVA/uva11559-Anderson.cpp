/*
 * Anderson A. Fontana
 * Uva 11559 - Event Planning
 */

#include <iostream>

using namespace std;

int main()
{
	
	int n,b,h,w, menor_orcamento, orcamento_atual,custo,camas;
	bool camas_suficiente;
	while (cin >> n >> b >> h >> w)
	{
		menor_orcamento = -1;
		for (int i = 0; i < h; ++i)
		{
			camas_suficiente = false;
			cin >> custo;
			for (int j = 0; j < w; ++j)
			{
				cin >> camas;
				if (camas >= n)
					camas_suficiente = true;
			}
			orcamento_atual = n * custo;
			if((menor_orcamento == -1 || menor_orcamento > orcamento_atual) && camas_suficiente)
				menor_orcamento = orcamento_atual;
		}
		if (menor_orcamento <= b && menor_orcamento != -1)
			cout << menor_orcamento << endl;
		else
			cout << "stay home" << endl;
	}
	return 0;
}