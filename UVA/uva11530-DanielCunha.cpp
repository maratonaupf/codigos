#include <iostream>
#include <map>

using namespace std;

int main() {
    int T, q, c = 0;
    string s;

    map<char, int> m {
        {'a', 1}, {'d', 1}, {'g', 1}, {'j', 1}, {'m', 1}, {'p', 1}, {'t', 1}, {'w', 1}, {' ', 1},
        {'b', 2}, {'e', 2}, {'h', 2}, {'k', 2}, {'n', 2}, {'q', 2}, {'u', 2}, {'x', 2},
        {'c', 3}, {'f', 3}, {'i', 3}, {'l', 3}, {'o', 3}, {'r', 3}, {'v', 3}, {'y', 3},
        {'s', 4}, {'z', 4}
    };

    cin >> T;
    cin.ignore();
    while(T--) {
        getline(cin, s);
        
        q = 0;
        for(int i = 0; i < (int) s.size(); ++i)
            q += m[s[i]];

        cout << "Case #" << ++c << ": " << q << endl;
    }

    return 0;
}
