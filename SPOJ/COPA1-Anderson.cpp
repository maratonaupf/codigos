/*
 * Anderson A. Fontana
 * spoj COPA1 - Copa do mundo
 */

#include <iostream>
#include <vector>

using namespace std;

char joga(vector<char> &equipe, int tam)
{
	if (tam == 1)
		return equipe[0];
	int x, y;
	vector<char> proxFase;
	for (int i = 0; i < tam; i+=2)
	{
		cin >> x >> y;
		if (x>y)
			proxFase.push_back(equipe[i]);
		else
			proxFase.push_back(equipe[i+1]);
	}
	return joga(proxFase, tam/2);
}

int main()
{
	vector<char> equipe = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
	cout << joga(equipe, 16) << endl;
	return 0;
}