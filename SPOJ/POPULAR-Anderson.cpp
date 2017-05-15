/*
 * Anderson A. Fontana
 * spoj POPULAR - Popularidade
 */

#include <iostream>

using namespace std;

int main()
{
	int N, i,j, aux, maior;
	while (cin >> N && N != 0)
	{
		for (i = 0; i < N; ++i)
		{
			for (j = 0; j < N; ++j)
			{
				cin >> aux;
				vet[j] += aux;
			}
		}

		for (i = 0; i < N; ++i)
			if (i == 0 || vet[i] > maior)
				maior = vet[i];

		cout << maior << endl;

		for (int i = 0; i < N; ++i)
			vet[i] = 0;
	}

	return 0;
}