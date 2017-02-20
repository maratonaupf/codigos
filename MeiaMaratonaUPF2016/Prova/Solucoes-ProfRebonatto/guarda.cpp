#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int d;
    float x,  vf, vg;
    
    while(cin >> d >> vf >> vg){
        x = sqrt(d * d + 144);
        if ( (12.0 / vf) >= (x / vg) )
            cout << "S\n";
        else
            cout << "N\n";
    }    
    return 0;
}
