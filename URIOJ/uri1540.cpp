#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

int main(void){	
	int N, a1, a2;
	double c1, c2, gr;
	string s;
	stringstream ss;
	cin >> N;
	while(N--){ s = "";
		cin >> a1 >> c1 >> a2 >> c2;
		gr= trunc(100.0 * ((c2-c1) / ((double) a2-a1) ) );
		gr/= 100.0;
		ss << fixed << setprecision(2) << gr;
		s += ss.str();
		ss.str ("");
		s[s.size()-3]=',';
		cout << s << endl;
		s.clear();
	}
	return 0;
}
