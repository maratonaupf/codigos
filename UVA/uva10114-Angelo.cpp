#include <iostream>

using namespace std;

int main(){

    int dur, record;
    double pay, amount;

    cin >> dur >> pay >> amount >> record;

    while(dur > 0){
        double rates[record][2], nowRate=0, ow;
        int K, curMonth = 0;
        double parcel = amount/dur;

        ow = amount;
        amount += pay;

        for(int i = 0; i < record; i++) cin >> rates[i][0] >> rates[i][1];
        nowRate=rates[0][1];
        for(K = 0; K <= dur; K++){
            if(K == rates[curMonth][0]){
                nowRate=rates[curMonth][1];
                if(curMonth < record-1) curMonth++;
            }
            amount -= (amount*nowRate);
            if(K != 0) ow -= parcel;
            if(amount > ow) break;


        }

        cout << K;
        if(K != 1) cout << " months";
        else cout << " month";
        cout << endl;

        cin >> dur >> pay >> amount >> record;
    }

}
