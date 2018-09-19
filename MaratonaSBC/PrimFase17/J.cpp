#include<iostream>
using namespace std;

int main()
{
	int sum{0};
	string s;
	cin >> s;
	for (auto c : s)
		sum+= c-'0';
	
	if (sum%3 == 0)
		cout << 0 << endl;
	else if (sum%3 == 2)
		cout << 2 << endl;
	else
		cout << 1 << endl;
	return 0;
}
