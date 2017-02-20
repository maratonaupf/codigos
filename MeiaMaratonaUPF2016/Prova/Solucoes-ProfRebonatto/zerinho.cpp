#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b, c;
    
    while(cin >> a >> b >> c){
        if ( (a == b) && (b == c) )
            cout << "*"; 
        else if (a == b)
            cout << "C";
        else if (a == c)
            cout << "B";
        else
            cout << "A";
        cout << endl;
    }    
    return 0;
}
