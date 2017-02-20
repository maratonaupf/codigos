#include<iostream>
#include<ctype.h>
#include<queue>

using namespace std;

int main(void){
	queue<int> fila;
	int aux;
	char op;
	while(cin >> op){
		switch(toupper(op)){
			case 'E':
				cin >> aux;
				fila.push(aux);
				cout << "Enfileirou " << aux << endl;
			break;
			case 'F':
				if(fila.empty()) cout << "Fila vazia" << endl;
				else cout << "Frente: " << fila.front() << endl;
			break;
			case 'D':
				if(fila.empty()) cout << "Fila vazia" << endl;
				else{
					cout << "Tirando da fila: " << fila.front() << endl;
					fila.pop();
				}
			break;
		}
	}
	while(!fila.empty()){
		cout << "Tirando da fila: " << fila.front() << endl;
		fila.pop();
	}
	return 0;
}
