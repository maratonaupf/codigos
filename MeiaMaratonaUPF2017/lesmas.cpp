#include <iostream>

using namespace std;

int main()
{
	int L, V, maior;
	
	while (cin >> L)
	{
		maior = 0;
		for (int i = 0; i < L; ++i)
		{
			cin >> V;
			if (V > maior)
				maior = V;
		}
		if (maior < 10)
			cout << 1 << endl;
		else if (10 <= maior && maior < 20)
			cout << 2 << endl;
		else
			cout << 3 << endl;
	}
	return 0;
}
