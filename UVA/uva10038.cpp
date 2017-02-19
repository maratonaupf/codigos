#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

int main(void){
	int N, i;
	int atual, ant, dif;
	vector<bool> v;
	bool isJolly;
	while(scanf("%d", &N) != EOF){
		v.assign(N, false);
		v[0] = true;
		scanf("%d", &ant);
		for(i = 1; i < N; i++){
			scanf("%d", &atual);
			dif = abs(ant-atual);
			if(dif < N) v[dif] = true;
			ant = atual;
		}
		isJolly = true;
		for(i = 1; i < N; i++){
			if(v[i] == false){
				isJolly = false;
				break;
			}
		}
		printf("%s\n", isJolly ? "Jolly" : "Not jolly");
	}
	return 0;
}
