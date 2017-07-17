/*
 * Anderson A. Fontana
 * Uri 1089 - Loop Musical
 */

#include <iostream>

using namespace std;

int main()
{
	int N, primeiro, anterior, proximo, cont;
	bool subindo, primeiroSubindo;
	while (cin >> N && N!=0)
	{
		cin >> primeiro;
		anterior = primeiro;
		cont = 1;
		cin >> proximo;

		primeiroSubindo = subindo = (anterior < proximo);
		// cout << anterior << (subindo ? " ^ " : " v ") << proximo << endl;
		N-=2;
		while (N--)
		{
			anterior = proximo;
			cin >> proximo;
			if ((subindo && anterior > proximo) || (!subindo && anterior < proximo))
			{
				cont++;
				subindo = !subindo;
				// cout << "++" << endl;
			}
			// cout << anterior << (subindo ? " ^ " : " v ") << proximo << endl;
		}
		if (subindo == primeiroSubindo)
			cont++;
		cout << cont << endl;
	}

	return 0;
}