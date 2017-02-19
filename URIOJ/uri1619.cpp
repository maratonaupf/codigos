#include<stdio.h>
#include<time.h>
#include<math.h>

time_t myTime(int y, int m, int d){
	time_t rawtime;
	struct tm p;
	time(&rawtime);
	p = *localtime(&rawtime);
	p.tm_year = y - 1900;
	p.tm_mon = m - 1;
	p.tm_mday = d;
	return mktime(&p);
}

int main(void){
	int N;
	int ay, am, ad, by, bm, bd;
	time_t at, bt;
	scanf("%d", &N);
	while(N--){
		scanf("%d-%d-%d %d-%d-%d", &ay, &am, &ad, &by, &bm, &bd);
		at = myTime(ay, am, ad);
		bt = myTime(by, bm, bd);
		printf("%d\n", (int) (fabs(difftime(at, bt)) / (3600*24)));
	}
	return 0;
}
