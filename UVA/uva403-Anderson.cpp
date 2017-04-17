/*
 * Anderson A. Fontana
 * Uva 403 - Postscript
 */

#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, vector<string>> bigLetter;

char page[60][60];

void load();
void putOnPaper(string align, int fontSize, int line, int position, string frase);
void writePage();
int main()
{
	memset(page, '.', sizeof(char) * 60 * 60);
	load();
	int line, position, fontSize;
	char lixo;
	string align, frase;
	while (cin >> lixo >> align)
	{
		if (align == "EOP")
		{
			writePage();
			memset(page, '.', sizeof(char) * 60 * 60);
			continue;
		}
		cin >> lixo >> fontSize >> line;
		if (align == "P")
			cin >> position;
		cin >> lixo;
		getline(cin, frase);
		frase.pop_back();

		putOnPaper(align, fontSize, line-1, position-1, frase);
	}
	return 0;
}

bool isValid(int x, int y)
{
	return (0<=x && x<60 && 0<=y && y<60);
}

void writeC1(int x, int y, string frase)
{
	for (size_t i = 0; i < frase.length(); ++i)
		if (isValid(x, y+i) && frase[i] != ' ')
				page[x][y+i] = frase[i];
}

void writeC5(int x, int y, char chr)
{
	int i, j;
	for (i = 0; i < 5; ++i)
		for (j = 0; j < 6; ++j)
			if (isValid(x+i, y+j) && bigLetter[chr][i][j]!='.')
				page[x+i][y+j] = bigLetter[chr][i][j];
}

void writeC5handle(int x, int y, string frase)
{
	int shift;
	for (size_t i = 0; i < frase.length(); ++i)
	{	
		shift = y+i*6;
		if (shift > -5 && shift < 60)
			writeC5(x, shift, frase[i]);
	}
}

void putOnPaper(string align, int fontSize, int line, int position, string frase)
{
	if(fontSize == 1)
		if (align == "P")
			writeC1(line, position, frase);
		else if (align == "R")
			writeC1(line, 60-frase.length(), frase);
		else if (align == "L")
			writeC1(line, 0, frase);
		else	// Center
			writeC1(line, 30-frase.length()/2, frase);
	else
		if (align == "P")
			writeC5handle(line, position, frase);
		else if (align == "R")
			writeC5handle(line, 60-(frase.length()*6), frase);
		else if (align == "L")
			writeC5handle(line, 0, frase);
		else	// Center
			writeC5handle(line, 30-(frase.length()*6)/2, frase);
}

void writePage()
{
	int i, j;
	for (i = 0; i < 60; ++i)
	{
		for (j = 0; j < 60; ++j)
			cout << page[i][j];
		cout << endl;
	}
	cout << endl;
	for (i = 0; i < 60; ++i)
		cout << '-';
	cout << endl << endl;
}

void load()
{
	bigLetter['A'] = {".***..","*...*.","*****.","*...*.","*...*."};
	bigLetter['B'] = {"****..","*...*.","****..","*...*.","****.."};
	bigLetter['C'] = {".****.","*...*.","*.....","*.....",".****."};
	bigLetter['D'] = {"****..","*...*.","*...*.","*...*.","****.."};
	bigLetter['E'] = {"*****.","*.....","***...","*.....","*****."};
	bigLetter['F'] = {"*****.","*.....","***...","*.....","*....."};
	bigLetter['G'] = {".****.","*.....","*..**.","*...*.",".***.."};
	bigLetter['H'] = {"*...*.","*...*.","*****.","*...*.","*...*."};
	bigLetter['I'] = {"*****.","..*...","..*...","..*...","*****."};
	bigLetter['J'] = {"..***.","...*..","...*..","*..*..",".**..."};
	bigLetter['K'] = {"*...*.","*..*..","***...","*..*..","*...*."};
	bigLetter['L'] = {"*.....","*.....","*.....","*.....","*****."};
	bigLetter['M'] = {"*...*.","**.**.","*.*.*.","*...*.","*...*."};
	bigLetter['N'] = {"*...*.","**..*.","*.*.*.","*..**.","*...*."};
	bigLetter['O'] = {".***..","*...*.","*...*.","*...*.",".***.."};
	bigLetter['P'] = {"****..","*...*.","****..","*.....","*....."};
	bigLetter['Q'] = {".***..","*...*.","*...*.","*..**.",".****."};
	bigLetter['R'] = {"****..","*...*.","****..","*..*..","*...*."};
	bigLetter['S'] = {".****.","*.....",".***..","....*.","****.."};
	bigLetter['T'] = {"*****.","*.*.*.","..*...","..*...",".***.."};
	bigLetter['U'] = {"*...*.","*...*.","*...*.","*...*.",".***.."};
	bigLetter['V'] = {"*...*.","*...*.",".*.*..",".*.*..","..*..."};
	bigLetter['W'] = {"*...*.","*...*.","*.*.*.","**.**.","*...*."};
	bigLetter['X'] = {"*...*.",".*.*..","..*...",".*.*..","*...*."};
	bigLetter['Y'] = {"*...*.",".*.*..","..*...","..*...","..*..."};
	bigLetter['Z'] = {"*****.","...*..","..*...",".*....","*****."};
	bigLetter[' '] = {"......","......","......","......","......"};
}
