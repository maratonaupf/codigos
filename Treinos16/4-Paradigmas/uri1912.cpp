//#include<stdio.h>
#include<iostream>
#include<iomanip>
#define MAX 112345
//#define DEBP

using namespace std;

#define EPS 1e-5
int cmp(double x, double y){
	return (x <= y + EPS) ? (x + EPS < y) ? -1 : 0 : 1;
}

double area(int N, int V[], double cut){
	double acum = 0.0;
	for(int i = 0; i < N; i++){
		if(cmp(V[i], cut) == 1)
			acum += (double)V[i] - cut;
	}
	return acum;
}

double binSearch(int N, int A, int V[], double fim){
	double inic = 0.0, meio = fim/2.0, ans = -1.0;
	
	while(cmp(ans, (double)A) != 0){
		ans = area(N, V, meio);
		if(ans > A) inic = meio;
		if(ans < A) fim = meio;
		// Para evitar overflow
		// A+B / 2 == A + (B-A) / 2
		meio = inic + (fim-inic) / 2.0;
	}
	return meio;
}

int main(void){
	int N, A;
	int V[MAX];
	//while(scanf("%d %d", &N, &A), N){
	while(cin >> N >> A, N != 0){
		int acum = 0, 
			maior = 0;
		
		for(int i = 0; i < N; i++){
			//scanf("%d", &V[i]);
			//scanf("%d", V+i);
			cin >> V[i];
			//acum += V[i];
			acum = acum + V[i];
			if(V[i] > maior){
				maior = V[i];
			}
		}
		
		if(acum == A){ 
			//printf(":D\n");
			cout << ":D" << endl;
		}
		else if(acum < A){
			//printf("-.-\n");
			cout << "-.-" << endl;
		}
		else{
			//printf("%.4lf\n", binSearch(N, A, V, maior));
			double resp = binSearch(N, A, V, maior);
			cout << fixed << setprecision(4) << resp << endl;
		}
	}
	return 0;
}
