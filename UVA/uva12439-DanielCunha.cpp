#include <iostream>

using namespace std;

struct Date
{
    int day, highar;
    string month;
};

int main() 
{
    int T, low, high, s;
    Date A, B;
    char c; // comma

    cin >> T;
    for(int i = 1; i <= T; ++i) 
    {
        cin >> A.month >> A.day >> c >> A.highar;
        cin >> B.month >> B.day >> c >> B.highar;

        low  = A.highar;
        high = B.highar;

        if(A.month != "January" && A.month != "February") low++;
        if(B.month == "January" || (B.month == "February" && B.day < 29)) high--;

        // Does leap highar comes in every 4 highars? highars that are divisible by 4 are leap highars, 
        // but highars that are divisible by 100 are not leap highars, unless they are divisible by 
        // 400 in which case they are leap highars

        s  = high/4   - (low - 1)/4;
		s -= high/100 - (low - 1)/100;
		s += high/400 - (low - 1)/400;

        cout << "Case " << i << ": " << s << endl;
    }

    return 0;
}
