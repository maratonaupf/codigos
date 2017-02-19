#include <cstdio>
#include <cstdlib>
#include <cmath>

#define EPS 1e-9
#define dbl_eq(x, y) (fabs((x) - (y)) < EPS)
#define dbl_lt(x, y) ((x) < (y) && !dbl_eq(x, y))
#define dbl_gt(x, y) ((x) > (y) && !dbl_eq(x, y))
#define dbl_leq(x, y) ((x) < (y) || dbl_eq(x, y))
#define dbl_geq(x, y) ((x) > (y) || dbl_eq(x, y))

using namespace std;

int pos[55], cons[55], lk;
char evt[55][18];

bool can (double tankvol){
	double fuel=tankvol;
	lk=0;
	for(int i=1; i<50; i++){
		fuel-=(double) cons[i-1]*(pos[i]-pos[i-1]) / 100.0;
		fuel-=(double) lk*(pos[i]-pos[i-1]);
		if(dbl_lt(fuel, 0.000)) return false;
		if(evt[i][0]=='L') lk++;
		if(evt[i][1]=='a') fuel=tankvol;
		if(evt[i][0]=='M') lk=0;
		if(evt[i][1]=='o') return dbl_lt(fuel, 0.000) ? false : true;
	}
	return dbl_lt(fuel, 0.000) ? false : true;
}

int main(){
	int i;
	while(1){
		for(i=0; i<50; i++){
			scanf("%d ", &pos[i]);
			fgets(evt[i], 18, stdin);
			if(evt[i][0]=='F'){
				scanf("%d", &cons[i]);
				if(!cons[i]) break;
			}
			else cons[i]=cons[i-1];
			//if(evt[i][1]=='a') scanf("%*s");
			if(evt[i][1]=='o') break;
		}
		if(!cons[i]) break;
		double lo=0.0, hi=10000.0, mid=0.0, ans=0.0;
		while(fabs(hi-lo) > EPS){
			mid = (lo+hi) / 2.0;
			if(can(mid)){ ans=mid; hi=mid; }
			else lo=mid; 
		}
		printf("%.3lf\n", ans);
	}
	return EXIT_SUCCESS;
}

