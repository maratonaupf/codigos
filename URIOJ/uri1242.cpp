#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
using namespace std;
 
int main() {
    string s;
    while(cin >> s) {
        stack<char> p;
        int cont = 0;
        for(int i=0; i<s.size(); i++) {
            if(!p.empty() && (
                s[i] == 'B' && p.top() == 'S' ||
                s[i] == 'S' && p.top() == 'B' ||
                s[i] == 'F' && p.top() == 'C' ||
                s[i] == 'C' && p.top() == 'F')) {
                  p.pop();
                  cont++;
            }else{
                p.push(s[i]);
            }
        }
        printf("%d\n", cont);
    }
    return EXIT_SUCCESS;
}
