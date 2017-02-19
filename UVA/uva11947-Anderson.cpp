/*
 * Anderson A. Fontana
 * Uva 11947 - Cancer or Scorpio
 */

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

struct date
{
	int dia,
		mes,
		ano;
};

date string2date(string s)
{
	date data;
	data.mes = (s[0] - '0') * 10 + (s[1] - '0');
	data.dia = (s[2] - '0') * 10 + (s[3] - '0');
	data.ano = (s[4] - '0') * 1000 + (s[5] - '0') * 100 + (s[6] - '0') * 10 + (s[7] - '0');
	return data;
}

string signo(date data)
{
	if ( (data.mes ==  1 && data.dia >= 21) || (data.mes ==  2 && data.dia <= 19) ) return "aquarius";
	if ( (data.mes ==  2 && data.dia >= 20) || (data.mes ==  3 && data.dia <= 20) ) return "pisces";
	if ( (data.mes ==  3 && data.dia >= 21) || (data.mes ==  4 && data.dia <= 20) ) return "aries";
	if ( (data.mes ==  4 && data.dia >= 21) || (data.mes ==  5 && data.dia <= 21) ) return "taurus";
	if ( (data.mes ==  5 && data.dia >= 22) || (data.mes ==  6 && data.dia <= 21) ) return "gemini";
	if ( (data.mes ==  6 && data.dia >= 22) || (data.mes ==  7 && data.dia <= 22) ) return "cancer";
	if ( (data.mes ==  7 && data.dia >= 23) || (data.mes ==  8 && data.dia <= 21) ) return "leo";
	if ( (data.mes ==  8 && data.dia >= 22) || (data.mes ==  9 && data.dia <= 23) ) return "virgo";
	if ( (data.mes ==  9 && data.dia >= 24) || (data.mes == 10 && data.dia <= 23) ) return "libra";
	if ( (data.mes == 10 && data.dia >= 24) || (data.mes == 11 && data.dia <= 22) ) return "scorpio";
	if ( (data.mes == 11 && data.dia >= 23) || (data.mes == 12 && data.dia <= 22) ) return "sagittarius";
	if ( (data.mes == 12 && data.dia >= 23) || (data.mes ==  1 && data.dia <= 20) ) return "capricorn";
	return NULL;
}

int main()
{
	int i, n;
	cin >> n;
	date data;
	string s;
	cin.ignore();
	for (i = 1; i <= n; ++i)
	{
		struct tm t = {0};
		getline(cin, s);
		data = string2date(s);

		t.tm_mday = data.dia;
		t.tm_mon = data.mes-1;
		t.tm_year = data.ano-1900;
		t.tm_mday += 280;
		mktime(&t);
		char buffer[11];
		strftime(buffer, 11, "%m%d%Y", &t);
		data = string2date(string(buffer));

		cout << i << " " << ( data.mes<10 ? "0" : "") << data.mes
			 << "/" << ( data.dia<10 ? "0" : "") << data.dia
			 << "/" << data.ano << " " << signo(data) << endl;
	}
	return 0;
}