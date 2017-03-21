//#include<stdio.h>
#include<iostream>

using namespace std;

int T1, T2, A, V, R;
int i, tempo, voltas, stops;

bool compensa(){
	int vr = (V <= R-i) ? V : R-i;
	return vr*T1 + A < vr*T2;
}

void simulacao(){
	tempo = 0, stops = 0;
	voltas = 1;
	for(i = 1; i <= R; i++){
		tempo += voltas > V ? T2 : T1;
		if(voltas >= V && compensa()){
			voltas = 0;
			stops++;
			tempo += A;
		}
		voltas++;
	}
	//printf("%d %d\n\n", tempo, stops);
	cout << tempo << " " << stops << endl << endl;
}

int main(void){
	int tests;
	//scanf("%d", &tests);
	cin >> tests;
	for(int tc = 1; tc <= tests; tc++){
		//scanf("%d %d %d %d %d", &T1, &T2, &A, &V, &R);
		cin >> T1 >> T2 >> A >> V >> R;
		//printf("Teste #%d\n", tc);
		cout << "Teste #"<< tc << endl;
		simulacao();
	}
	return 0;
}
