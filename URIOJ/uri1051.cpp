#include<cstdio>

int main(void){	
	double sal, assalto;
	while(scanf("%lf", &sal) != EOF){
		assalto=0.0;
		if(sal <= 2000.0)
			puts("Isento");
		else{
			sal -= 2000.0;
			if(sal <= 1000.0)
				assalto += (sal * 8.0) / 100.0;
			else{
				assalto += 80.0;
				sal-= 1000.0;
				if(sal <= 1500.0)
					assalto += (sal * 18.0) / 100.0;
				else{
					assalto += 270.0;
					sal-= 1500.0;
					assalto += (sal * 28.0) / 100.0;
				}
			}
			printf("R$ %.2lf\n", assalto);
		}
	}
	return 0;
}
