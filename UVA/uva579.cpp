#include<stdio.h>
#include<math.h>
#define EPS 1e-9

double angle(int h, int min){
	double ah, am;
	ah = (double)h * 30.0 + (double)min * 0.5;
	am = (double)min * 6.0;
	#ifdef DEBP
	printf("h %.3lf | ", ah);
	printf("m %.3lf | ", am);
	#endif
	return fmin(fabs(ah-am), fabs(360.0 - fabs(ah-am)));
}

int main(void){
	int h, min;
	while(scanf("%d:%d\n", &h, &min), h != 0){
		printf("%.3lf\n", angle(h, min));
	}
	return 0;
}
