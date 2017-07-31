// poodlemg

#include<iostream>
#include <math.h>

using namespace std;

int main() {
    double N , P;

    while (cin >> N >> P &&  N !=0 && P!=0 ){
        int T = ceil(N/P);
        if ( T <= 6){
            cout << "Poodle" << endl;
            continue;
        }
        if( T >= 20){
            cout << "Poooooooooooooooodle" << endl;
            continue;
        }
        cout << 'P'; T --;
        for (int i = 1 ; i < T-2 ; i++ )
            cout << 'o';
        cout  << "dle" << endl ;




    }



    return 0 ;
}
