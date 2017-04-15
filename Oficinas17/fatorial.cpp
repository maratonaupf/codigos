/*
 * Leonardo Deliyannis Constantin
 * Fatorial em Vetor
 */

#include <iostream>
#define MAX 21

using namespace std;

typedef unsigned long long ull;

int main(){
	int N, i;
	ull fat[MAX];
	cin >> N;
	fat[0] = 1;
	for(i = 1; i <= N; i++){
		fat[i] = fat[i-1] * i;
		cout << fat[i] << endl;
	}
	return 0;
}
