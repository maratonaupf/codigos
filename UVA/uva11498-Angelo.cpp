#include <iostream>

using namespace std;

int main(){

    int k;

    cin >> k;
    while(k){
        int n, m;
        cin >> n >> m;

        while(k--){
            int x, y;
            cin >> x >> y;

            if(x == n || y == m) cout << "divisa";
            else if(x < n){
                if(y < m) cout << "SO";
                else cout << "NO";
            }else{
                if(y < m) cout << "SE";
                else cout << "NE";
            }

            cout << endl;

        }

        cin >> k;
    }
}
