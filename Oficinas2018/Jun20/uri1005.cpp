#include <stdio.h>

int main(){
	double a, b;
	double media;
	while(scanf("%lf %lf", &a, &b) != EOF){
		media = (a * 3.5 + b * 7.5) / 11.0;
		cout << "MEDIA = " << fixed << setprecision(5) << media << endl;
	}
	return 0;
}
