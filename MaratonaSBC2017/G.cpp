#include <iostream>
using namespace std;
typedef unsigned long long ull;
#define P 1000000007
ull val[51][112345];
int main() {
	int t,min,max;
	cin >> t >> min >> max;
	for(int j=min;j<=max;j++) {
		val[0][j]=1;
	}
	for(int i=1;i<t;i++) {
		for(int j=min;j<=max;j++) {
			if(j > min && j < max) {
				val[i][j]=val[i-1][j-1]+val[i-1][j+1];
			} else if(j == min) {
				val[i][j]=val[i-1][j+1];
			} else if(j == max) {
				val[i][j]=val[i-1][j-1];
			}
			if(val[i][j]>P)
				val[i][j]-=P;
		}
	}
	ull soma=0;
	t--;
	for(int j=min;j<=max;j++) {
		soma+=val[t][j];
		if(soma>P)
			soma-=P;
	}
	cout << soma << endl;
}
