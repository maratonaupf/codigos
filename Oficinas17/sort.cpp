#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 11234

int main(){
	int v[MAX];
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> v[i];
	}
	sort(v, v+N);
	for(int i = 0; i < N; i++){
		cout << v[i] << endl;
	}
	return 0;
}
