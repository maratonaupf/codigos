#include <iostream>

using namespace std;

int main(){

    int h, u, d, f;



    cin >> h >> u >> d >> f;



    while(h){

        float fat = u*f/100.0;
        float dist = 0, spd = u;
        int day = 0;



        while(dist <= h && dist >= 0){
            day++;
            if(spd > 0) dist += spd;
            if(dist > h) break;
            dist -= d;
            spd -= fat;
        }

        if(dist > 0) cout << "success";
        else cout << "failure";
        cout << " on day " << day << endl;

        cin >> h >> u >> d >> f;

    }

}
