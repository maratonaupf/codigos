#include<stdio.h>
#include<time.h>
#include<math.h>
#define LEN 12

struct tm myTime(char *s){
	time_t rawtime, newtime;
	struct tm p;
	int m, d, y;
	m = (s[0] - '0') * 10 + (s[1] - '0');
	d = (s[2] - '0') * 10 + (s[3] - '0');
	y = (s[4] - '0') * 1000 + 
		(s[5] - '0') *  100 +
		(s[6] - '0') *   10 +
		(s[7] - '0');
	time(&rawtime);
	p = *localtime(&rawtime);
	p.tm_year = y - 1900;
	p.tm_mon = m - 1;
	p.tm_mday = d + 40*7;
	newtime = mktime(&p);
	return *localtime(&newtime);
}

const int lastDayOfSign[12]{
	20, 21, 21, 22,
	21, 23, 23, 22,
	22, 20, 19, 20
};

int signCode(struct tm dt){
	int ret = (dt.tm_mon+9) % 12;
	return (dt.tm_mday <= lastDayOfSign[ret]) ? ret : (ret+1)%12;
}

const char ZODIAC[12][LEN]{
	"aries", "taurus", "gemini", "cancer", 
	"leo", "virgo", "libra", "scorpio", 
	"sagittarius", "capricorn", "aquarius", "pisces"
};

int main(void){
	int T, caso;
	char data[LEN];
	struct tm birth;
	scanf("%d\n", &T);
	for(caso = 1; caso <= T; caso++){
		fgets(data, LEN, stdin);
		birth = myTime(data);
		printf("%d %02d/%02d/%04d %s\n", caso, 
			birth.tm_mon+1, birth.tm_mday, birth.tm_year+1900, 
			ZODIAC[signCode(birth)]);
	}
	return 0;
}
