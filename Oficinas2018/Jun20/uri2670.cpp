#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a1, a2, a3;
	while(cin >> a1 >> a2 >> a3){
		cout << min(a2*2 + a3*4, min(a1*2 + a3*2, a1*4 + a2*2)) << endl;
	}
	return 0;
}
