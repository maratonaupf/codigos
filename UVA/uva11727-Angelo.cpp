#include <iostream>

using namespace std;

int main(){

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++){

        int a, b, c;

        cin >> a >> b >> c;

        cout << "Case " << i << ": ";

        if((a > b && a < c) || (a < b && a > c)) cout << a;
        else if((b > a && b < c) || (b < a && b > c)) cout << b;
        else cout << c;

        cout << endl;


    }

}
