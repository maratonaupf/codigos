#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void){	
	int T, tc = 0, L, i, s;
	double b, iv, ev;
	char P[256], stat[4][4];
	strcpy(stat[0], "HP");
	strcpy(stat[1], "AT");
	strcpy(stat[2], "DF");
	strcpy(stat[3], "SP");
	scanf("%d", &T);
	getchar();
	while(tc++ < T){
		scanf("%s %d", P, &L);
		printf("Caso #%d: %s nivel %d\n", tc, P, L);
		for(i = 0; i < 4; i++){
			scanf("%lf %lf %lf", &b, &iv, &ev);
			s = ((iv + b + sqrt(ev) / 8.0  + (i?0:50)) * L ) / 50 + (i ? 5 : 10);
			printf("%s: %d\n", stat[i], s);
		}
	}
	return 0;
}
