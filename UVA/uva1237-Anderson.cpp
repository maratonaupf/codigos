/*
 * Anderson A. Fontana
 * Uva 1237 - Expert Enough?
 */

#include <iostream>
#include <vector>

using namespace std;

struct data
{
	string	M;
	int 	L,
			H;
};

int main()
{
	vector<data> database;
	int T, D, L, H, Q, P;
	string M, maker;
	cin >> T;
	while (T--)
	{
		cin >> D;
		while (D--)
		{
			cin >> M >> L >> H;
			database.push_back({M, L, H});
		}
		cin >> Q;
		while (Q--)
		{
			cin >> P;
			maker = "UNDETERMINED";
			for (auto it = database.begin(); it != database.end(); ++it)
				if (it->L <= P && P <= it->H)
				{
					if (maker == "UNDETERMINED")
						maker = it->M;
					else
					{
						maker = "UNDETERMINED";
						break;
					}
				}
			cout << maker << endl;
		}

		database.clear();
		if (T>0)
			cout << endl;
	}
	return 0;
}