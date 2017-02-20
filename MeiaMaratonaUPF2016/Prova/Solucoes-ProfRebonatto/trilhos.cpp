#include <cstdlib>
#include <iostream>
#include <deque>
#include <stack>
#include <sstream>
 
using namespace std;
 
int main (void)
{
    int tremTamanho;
    deque<char> original;
    deque<char> desejado;
    stack<char> estacao;
    while (true) {
        string line;
        getline(cin, line);
        istringstream(line) >> tremTamanho;
        if (tremTamanho == 0) break;
        line.clear();
        getline(cin, line);
        // jump over the spaces
        for (int i = 0; i < tremTamanho*2; i+=2) {
            original.push_back(line[i]);
        }
        line.clear();
        getline(cin, line);
        for (int i = 0; i < tremTamanho*2; i+=2) {
            desejado.push_back(line[i]);
        }
 
        string movimentos;
        while (!desejado.empty()) {
            char frenteB = desejado.front();
            desejado.pop_front();
 
 
            if (!estacao.empty() && frenteB == estacao.top()) {
                estacao.pop();
                movimentos += "R";
                continue;
            } else {
                while (!original.empty() && frenteB != original.front()) {
                    estacao.push(original.front());
                    original.pop_front();
                    movimentos += "I";
                }
 
                if (original.empty()) {
                    movimentos += " Impossible";
                    break;
                } else {
                    original.pop_front();
                    movimentos += "IR";
                    continue;
                }
            }
        }
        cout << movimentos << endl;
 
        original.clear();
        desejado.clear();
        while (!estacao.empty()) estacao.pop();
    }
 
    return EXIT_SUCCESS;
}
