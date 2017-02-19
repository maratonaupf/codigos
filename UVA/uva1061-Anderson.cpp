/*
 * Anderson A. Fontana
 * Uva 1061 - Consanguine Calculations
 */

#include <iostream>
#include <list>
#include <map>

using namespace std;

map<string, map<string, list<string>>> parents;
map<string, map<string, list<string>>> parentChild;

char rh(string &auxBlood);
void showCalc(map<string, map<string, list<string>>> &auxMap, string A, string B, bool rhP, bool rhN);
void load();

int main()
{
	load();
	string F, M, C; // Father, Mother, Child
	char rhF, rhM, rhC;
	int Case{1};
	bool rhP, rhN;
	while (cin >> F >> M >> C && F!="E" && M!="N" && C!="D")
	{
		rhF = rh(F); // Father
		rhM = rh(M); // Mother
		rhC = rh(C); // Child
		rhP = false; // Positive
		rhN = false; // Negative

		cout << "Case " << Case++ << ": ";
		if (C == "?")
		{
			if (rhF == '-' && rhM == '-')
				rhN = true;
			else
				rhP = rhN = true;
			cout << F << rhF << " " << M << rhM << " ";
			showCalc(parents, F, M, rhP, rhN);
		}
		else if(F == "?")
		{
			if (rhM == '-' && rhC == '+')
				rhP = true;
			else
				rhP = rhN = true;
			showCalc(parentChild, M, C, rhP, rhN);
			cout << " " << M << rhM << " " << C << rhC;
		}
		else
		{
			if (rhF == '-' && rhC == '+')
				rhP = true;
			else
				rhP = rhN = true;
			cout << F << rhF << " ";
			showCalc(parentChild, F, C, rhP, rhN);
			cout << " " << C << rhC;
		}
		cout << endl;

	}
	return 0;
}

char rh(string &auxBlood)
{
	if (auxBlood == "?")
		return '?';
	char auxRH;
	auxRH = auxBlood[auxBlood.length()-1];
	auxBlood.pop_back();
	return auxRH;
}

void showCalc(map<string, map<string, list<string>>> &auxMap, string A, string B, bool rhP, bool rhN)
{
	bool first = true;
	if (auxMap[A][B].empty())
	{
		cout << "IMPOSSIBLE";
		return;
	}
	if (auxMap[A][B].size() > 1 || (rhP && rhN)) cout << "{";
	for (auto it = auxMap[A][B].rbegin(); it != auxMap[A][B].rend(); ++it)
	{
		if (rhN)
		{
			if (first) first = false;
			else cout << ", ";
			cout << *it << "-";
		}
		if (rhP)
		{
			if (first) first = false;
			else cout << ", ";
			cout << *it << "+";
		}
	}
	if (auxMap[A][B].size() > 1 || (rhP && rhN)) cout << "}";
}

void load()
{
	parents["A"]["A"]  = {"A","O"};
	parents["A"]["B"]  = {"A","B","AB","O"};
	parents["A"]["AB"] = {"A","B","AB"};
	parents["A"]["O"]  = {"A","O"};
	parents["B"]["A"]  = {"A","B","AB","O"};
	parents["B"]["B"]  = {"B","O"};
	parents["B"]["AB"] = {"A","B","AB"};
	parents["B"]["O"]  = {"B","O"};
	parents["AB"]["A"] = {"A","B","AB"};
	parents["AB"]["B"] = {"A","B","AB"};
	parents["AB"]["AB"]= {"A","B","AB"};
	parents["AB"]["O"] = {"A","B"};
	parents["O"]["A"]  = {"A","O"};
	parents["O"]["B"]  = {"B","O"};
	parents["O"]["AB"] = {"A","B"};
	parents["O"]["O"]  = {"O"};

	parentChild["A"]["A"]  = {"A","B","AB","O"};
	parentChild["B"]["A"]  = {"A","AB"};
	parentChild["AB"]["A"] = {"A","B","AB","O"};
	parentChild["O"]["A"]  = {"A","AB"};
	parentChild["A"]["B"]  = {"B","AB"};
	parentChild["B"]["B"]  = {"A","B","AB","O"};
	parentChild["AB"]["B"] = {"A","B","AB","O"};
	parentChild["O"]["B"]  = {"B","AB"};
	parentChild["A"]["AB"] = {"B","AB"};
	parentChild["B"]["AB"] = {"A","AB"};
	parentChild["AB"]["AB"]= {"A","B","AB"};
	parentChild["O"]["AB"] = {};
	parentChild["A"]["O"]  = {"A","B","O"};
	parentChild["B"]["O"]  = {"A","B","O"};
	parentChild["AB"]["O"] = {};
	parentChild["O"]["O"]  = {"A","B","O"};
}