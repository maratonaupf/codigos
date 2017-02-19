#include<stdio.h>
//#define DEBP

int main(void){
	int day;
	double H, U, D, F, height;
	while(scanf("%lf %lf %lf %lf", &H, &U, &D, &F), H != 0){
		F = U*F / 100.0;
		height = 0.0;
		#ifdef DEBP
		printf("Day\tIn. Ht\tClimbed\tTop Ht.\tSliding\n");
		#endif
		for(day = 1; true; day++){
			#ifdef DEBP
			printf("%d\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", day, height, U,
				height+U, height+U-D);
			#endif
			height += U;
			if(height > H) break;
			height -= D;
			if(height < 0.0) break;
			U -= F;
			if(U < 0.0) U = 0.0;
		}
		printf("%s on day %d\n", height > H ? "success" : "failure", day);
	}
	return 0;
}
