/*
 * Leonardo Deliyannis Constantin, Gabriel Cena Kressin (ideias)
 * Maratona de Programação SBC 2017
 * E - Escala Musical
 */

#include <stdio.h>
#include <bitset>
#include <string>
using namespace std;

bool minor[12] = { 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0 };
string name[12] = { 
	"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", 
	"sol#", "la", "la#", "si" };

int main(){
	int N, note;
	bitset<12> bs;
	while(scanf("%d", &N) != EOF){
		bs.reset();
		while(N--){
			scanf("%d", &note);
			bs[(note-1)%12] = 1;
		}
		int ans = -1;
		for(int j = 0; j < 12; j++){
			bool aqui = true;
			for(int i = 0; i < 12; i++){
				if(bs[(j+i)%12] && minor[i]){
					aqui = false; break;
				}
			}
			if(aqui){ ans = j; break; }
		}
		printf("%s\n", (ans != -1) ? 
			name[ans].c_str() : "desafinado");
	}
	return 0;
}
