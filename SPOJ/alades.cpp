#include<iostream>

using namespace std;

int main(void){
	int h1, m1, h2, m2;
	int total;
	while(cin >> h1 >> m1 >> h2 >> m2, h1|| m1 || h2 || m2){
		if(h1 > h2 || (h1 == h2 && m1 > m2)) h2 += 24;
		m1 += h1 * 60;
		m2 += h2 * 60;
		total = m2 - m1;
		cout << total << endl;
	}
	return 0;
}
