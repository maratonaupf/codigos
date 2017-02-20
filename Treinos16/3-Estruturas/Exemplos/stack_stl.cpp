#include<iostream>
#include<ctype.h>
#include<stack>

using namespace std;

int main(void){
	stack<string> p;
	string s;
	char op;
	while(cin >> op){
		switch(toupper(op)){
			case 'E':
				cin >> s;
				p.push(s);
				cout << "Empilhou " << p.top() << endl;
			break;
			case 'T':
				if(p.empty()) cout << "Pilha vazia" << endl;
				else cout << "Topo: " << p.top() << endl;
			break;
			case 'D':
				if(p.empty()) cout << "Pilha vazia" << endl;
				else{
					cout << "Desempilhando " << p.top() << endl;
					p.pop();
				}
			break;
		}
	}
	while(!p.empty()){
		cout << "Desempilhando " << p.top() << endl;
		p.pop();
	}
	return 0;
}
