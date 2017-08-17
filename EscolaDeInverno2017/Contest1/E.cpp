#include<iostream>

using namespace std;

int main(){
	int K, sits, rest;
	bool tras, line;
	cin >> K;
	
	if (K > 4)
	{
		tras = true;
		K -= 4;
		sits = K / 3;
		rest = K % 3;
	}
	else
	{
		tras = false;
		rest = K;
		sits = 0;
	}
	
	cout << "+------------------------+" << endl;
	
	line = false;
	cout << "|";
	if (tras) cout << "O.";
	else if (!tras && rest>0) { cout << "O."; rest--;}
	else cout << "#.";
	for (int i = 0; i < 10; i++)
	{
		if (i < sits)
			cout << "O.";
		else if (tras && rest>0 && !line)
		{
			cout << "O.";
			rest--;
			line = true;
		}
		else
			cout << "#.";
	}
	cout << "|D|)" << endl;
//---
	line = false;
	cout << "|";
	if (tras) cout << "O.";
	else if (!tras && rest>0) { cout << "O."; rest--;}
	else cout << "#.";
	for (int i = 0; i < 10; i++)
	{
		if (i < sits)
			cout << "O.";
		else if (tras && rest>0 && !line)
		{
			cout << "O.";
			rest--;
			line = true;
		}
		else
			cout << "#.";
	}
	cout << "|.|" << endl;
//---
	line = false;
	cout << "|";
	if (tras) cout << "O.";
	else if (!tras && rest>0) { cout << "O."; rest--;}
	else cout << "#.";
	for (int i = 0; i < 10; i++)
	{
		cout << "..";
	}
	cout << "..|" << endl;
//---
	line = false;
	cout << "|";
	if (tras) cout << "O.";
	else if (!tras && rest>0) { cout << "O."; rest--;}
	else cout << "#.";
	for (int i = 0; i < 10; i++)
	{
		if (i < sits)
			cout << "O.";
		else if (tras && rest>0 && !line)
		{
			cout << "O.";
			rest--;
			line = true;
		}
		else
			cout << "#.";
	}
	cout << "|.|)" << endl;
	cout << "+------------------------+" << endl;
	
}
