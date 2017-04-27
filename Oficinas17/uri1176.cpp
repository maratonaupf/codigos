/*
 * Leonardo Deliyannis Constantin
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1176
 */

#include <iostream>
using namespace std;
#define MAX 61

typedef unsigned long long ull;

int main(){
	ull fib[MAX];
	int T, N, i;
	fib[0] = 0;
	fib[1] = 1;
	for(i = 2; i < MAX; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	cin >> T;
	while(T--){
		cin >> N;
		cout << "Fib(" << N << ") = " << fib[N] << endl;
	}
	return 0;
}
