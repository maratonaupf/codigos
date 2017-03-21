#include<stdio.h>
//#include<iostream>

//using namespace std;

int main(void){
	int mult[6];
	int N, L, i;
	//while(cin >> N){
	while(scanf("%d", &N) != EOF){
		for(i = 2; i <= 5; i++){
			mult[i] = 0;
		}
		while(N--){
			//cin >> L;
			scanf("%d", &L);
			for(i = 2; i <= 5; i++){
				if(L%i == 0){
					mult[i]++;
				}
			}
		}
		for(i = 2; i <= 5; i++){
			//cout << mult[i] << " Multiplo(s) de " << i << endl;
			printf("%d Multiplo(s) de %d\n", mult[i], i);
		}
	}
	return 0;
}
