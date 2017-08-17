/*
 * Leonardo Deliyannis Constantin
 * E - Bayan Bus
 */

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> vs;

void setBus(vs &bus){
	bus = {
		"+------------------------+",
	    "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
		"|#.#.#.#.#.#.#.#.#.#.#.|.|",
		"|#.......................|",
		"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
		"+------------------------+"
	};
}

int main(){
	vs bus;
	int i, j, N;
	while(scanf("%d", &N) != EOF){
		setBus(bus);
		for(j = 0; j < 26; j++){
			for(i = 1; i < 5 && N > 0; i++){
				if(bus[i][j] == '#'){
					bus[i][j] = 'O';
					N--;
				}
			}
		}
		for(i = 0; i < (int)bus.size(); i++){
			printf("%s\n", bus[i].c_str());
		}
	}
	return 0;
}
