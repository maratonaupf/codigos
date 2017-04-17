/*
 * Anderson A. Fontana
 * Uri 1228 - Grid de Largada
 */

#include <iostream>
#include <vector>

using namespace std;

int bubbleSort(vector<int> arr, int tam)
{
	int cont{0};
	for (int i = 0; i < tam-1; ++i)
		for (int j = 0; j < tam-1; ++j)
			if(arr[j] > arr[j+1] && ++cont)
				swap(arr[j], arr[j+1]);
	return cont;
}

int main()
{
	int i, N, aux;
	vector<int> larg, cheg;
	while (cin >> N)
	{
		larg.assign(N,0);
		cheg.assign(N,0);
		for (i = 0; i < N && cin >> aux; ++i)
			larg[aux-1] = i;
		for (i = 0; i < N && cin >> aux; ++i)
			cheg[i] = larg[aux-1];

		cout << bubbleSort(cheg, N) << endl;

		larg.clear();
		cheg.clear();
	}
	return 0;
}