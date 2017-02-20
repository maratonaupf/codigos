#include<stdio.h>
//#include<iostream>

//using namespace std;

int main(void){
	int abas, acoes;
	char acao[8];
	//while(cin >> abas >> acoes){
	while(scanf("%d %d", &abas, &acoes) != EOF){
		while(acoes--){
			//cin >> acao;
			scanf("%s", acao);
			if(acao[0] == 'f'){
				abas++;
			}
			else{
				abas--;
			}
		}
		//cout << abas << endl;
		printf("%d\n", abas);
	}
	return 0;
}
