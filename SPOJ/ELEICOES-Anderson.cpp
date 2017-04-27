/*
 * Anderson A. Fontana
 * spoj ELEICOES - Eleições
 */

#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main()
{
	int i, N, X;
	map<int, int> m;
	pair<int, int> maior;
	cin >> N;
	for (i = 0; i < N; ++i)
	{
		cin >> X;
		if (m.find(X) != m.end())
			m[X]++;
		else
			m[X] = 1;
	}

	maior.second = 0;
	for (auto it = m.begin(); it != m.end(); ++it)
		if (it->second > maior.second)
			maior = *it;

	cout << maior.first << endl;
	return 0;
}