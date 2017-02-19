#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void){
	int N, i;
	queue<int> fila;
	vector<int> descartadas;
	
	while(cin >> N, N){
		// criamos a "pilha" de cartas
		for(i = 1; i <= N; i++){
			fila.push(i);
		}
		// jogamos cartas fora
		while(fila.size() >= 2){
			descartadas.push_back(fila.front());
			fila.pop();
			fila.push(fila.front());
			fila.pop();
		}
		
		cout << "Discarded cards:";
		int tam = descartadas.size(); 
		
		for(i = 0; i < tam; i++){
			cout << " " << descartadas[i];
			if(i < tam - 1){
				cout << ",";
			}
			else{
				cout << endl;
			}
		}
		cout << "Remaining card: " << fila.front() << endl;
		descartadas.clear();
		while(fila.size()){
			fila.pop();
		}
	}
	return 0;
}
