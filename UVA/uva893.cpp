#include<stdio.h>
#include<time.h>

struct tm myTime(int toAdd, int d, int m, int y){
	time_t rawtime, newtime;
	struct tm p;
	time(&rawtime);
	p = *localtime(&rawtime);
	p.tm_year = y - 1900;
	p.tm_mon = m - 1;
	p.tm_mday = d + toAdd;
	newtime = mktime(&p);
	return *localtime(&newtime);
}

int main(void){
	int toAdd, day, mon, year;
	struct tm dt;
	while(scanf("%d %d %d %d", &toAdd, &day, &mon, &year), day != 0){
		dt = myTime(toAdd, day, mon, year);
		printf("%d %d %d\n", dt.tm_mday, dt.tm_mon+1, dt.tm_year+1900);
	}
	return 0;
}
