#include <iostream>

using namespace std;

int main(){

    int n, p;
    int t=0;
    string garbage;

    cin >> n >> p;

    while(n){
        int bestmet = 0, met;
        double bestprice = 0, price;
        string bestname, name;

        if(t) printf("\n");
        t++;

        cin.ignore();

        for(int i = 0; i < n; i++)
            getline(cin, garbage);

        getline(cin, bestname);
        cin >> bestprice >> bestmet;
        cin.ignore();

        for(int i = 0; i < bestmet; i++)
            getline(cin, garbage);

        for(int j = 1; j < p; j++){
            getline(cin, name);
            cin >> price >> met;
            cin.ignore();

            for(int i = 0; i < met; i++)
                getline(cin, garbage);

            if(met > bestmet || (met == bestmet && price < bestprice)){
                bestmet = met;
                bestname = name;
                bestprice = price;
            }

        }

        cout << "RFP #" << t << endl << bestname << endl;

        cin >> n >> p;

    }


}
