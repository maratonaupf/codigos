/*
 * Anderson A. Fontana
 * Uva 514 - Rails
 */

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int vag, org{1}, i;
	stack<int> station;
	queue<int> inList, outList;
	bool f;
	while (cin >> vag && vag!=0)
	{
		while (cin >> org && org!=0)
		{
			outList.push(org);
			for (i = 1; i < vag; i++)
			{
				cin >> org;
				outList.push(org);
			}
			for (i = 1; i <= vag; i++)
				inList.push(i);
			while (!inList.empty())
			{
				f = true;
				while (!inList.empty() && f){
					station.push(inList.front());
					if (inList.front() == outList.front())
						f = false;
					inList.pop();
				}
				if (inList.empty() && station.top() != outList.front())
					break;
				f = true;
				while (!station.empty() && f)
				{
					station.pop();
					outList.pop();
					if (station.empty())
						break;
					if (station.top() != outList.front())
						f = false;
				}
			}
			if (station.empty() && inList.empty() && outList.empty())
				cout << "Yes" << endl;
			else
				cout << "No" << endl;

			while(!station.empty())
				station.pop();
			while(!outList.empty())
				outList.pop();
			while(!inList.empty())
				inList.pop();
		}
		cout << endl;
	}
}
