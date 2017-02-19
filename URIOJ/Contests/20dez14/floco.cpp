#include<cstdio>
#include<cmath>
#include<cstdlib>

#define EPS 1e-9
#define dbl_eq(x, y) (fabs((x) - (y)) < EPS)
#define dbl_lt(x, y) ((x) < (y) && !dbl_eq(x, y))
#define dbl_gt(x, y) ((x) > (y) && !dbl_eq(x, y))
#define dbl_leq(x, y) ((x) < (y) || dbl_eq(x, y))
#define dbl_geq(x, y) ((x) > (y) || dbl_eq(x, y))

double tri_area(double l){ return ((l*l) *  sqrt(3.0)) / 4.0; }

int main(){
	double l, lados, ant, atual, mini;
	while(scanf("%lf", &l)!=EOF){
		ant=tri_area(l);
		lados=3.0;
		mini=ant/9.0;
		atual=ant+(mini*lados);
		while(fabs(atual-ant) > EPS){
			ant=atual;
			mini/=9.0;
			lados*=4.0;
			atual=ant+(mini*lados);
		}
		printf("%.2lf\n", atual);
	}
	return 0;
}
