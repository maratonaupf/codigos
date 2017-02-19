/*
 * Anderson A. Fontana
 * Uva 11034 - Ferry Loading IV
 */

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> r, l;
	int N, L, M, length, crossCout, atual;
	string side;
	cin >> N;
	while (N--)
	{
		cin >> L >> M;
		L *= 100;
		while (M--)
		{
			cin >> length >> side;
			if (side == "right")
				r.push_back(length);
			else 
				l.push_back(length);
		}
		crossCout = 0;
		side = "left";

		while (!l.empty() || !r.empty())
		{
			if (side == "right")
			{
				atual = 0;
				if (!r.empty())
				{
					while (!r.empty() && atual + r.front() <= L)
					{
						atual += r.front();
						r.pop_front();
					}
				}
				if (atual > 0 || !l.empty())
				{
					side = "left";
					crossCout++;
				}
			}

			if (side == "left")
			{
				atual = 0;
				if (!l.empty())
				{
					while (!l.empty() && atual + l.front() <= L)
					{
						atual += l.front();
						l.pop_front();
					}
				}
				if (atual > 0 || !r.empty())
				{
					side = "right";
					crossCout++;
				}
			}
		}
		cout << crossCout << endl;
		l.clear();
		r.clear();
	}
	return 0;
}