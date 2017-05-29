#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 22

typedef unsigned long long ull;

int contaDigitos(ull n){
	int digits = 0;
	if(n == 0ULL) return 1;
	while(n > 0ULL){
		n /= 10ULL;
		digits++;
	}
	return digits;
}

int main(){
	int N, M, i, j, x=3, sp[MAX];
	ull m[MAX][MAX], maior;
	cin >> N;
	while(N--){
		cin >> M;
		for(i = 0; i < M; i++){
			for(j = 0; j < M; j++){
				cin >> m[i][j];
				m[i][j] *= m[i][j];
			}
		}
		for(j = 0; j < M; j++){
			maior = 0ULL;
			for(i = 0; i < M; i++)
				if(maior < m[i][j]) maior = m[i][j];
			sp[j] = contaDigitos(maior);
		}
		cout << "Quadrado da matriz #" << ++x << ":\n";
		for(i = 0; i < M; i++){
			for(j = 0; j < M; j++){ 
				if(j > 0) cout << " ";
				cout << right << setw(sp[j]) << m[i][j];
			} cout << "\n";
		}
		if(N > 0) cout << "\n";
	}
	return 0;
}
