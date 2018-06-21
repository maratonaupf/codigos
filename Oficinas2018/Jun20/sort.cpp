#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 112345

int main(){
	// int v[MAX_N];
	int N, i;
	cin >> N;
	vector<int> v;
	v.resize(N);
	for(i = 0; i < N; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for(i = 0; i < N; i++){
		cout << v[i] << ((i < N-1) ? ' ' : '\n');
	}
	v.clear();
	return 0;
}
